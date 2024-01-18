#include "/home/kpit/Downloads/Walkie-Talkie/Client/api/ClientSocket.h"

#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

ClientSocket::ClientSocket() : mclientSocket(-1) {
}
 
ClientSocket::~ClientSocket() {
    DisConnect();
}
 
void* ClientSocket::RecieveMessages(void* arg) {
    ClientSocket* clientSocket = reinterpret_cast<ClientSocket*>(arg);
    char buffer[256];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket->mclientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Connection closed by server\n";
            break;
        }
        std::cout << "Server message: " << buffer << std::endl;
    }
    return nullptr;
}
 
void ClientSocket::Connect(const std::string& ipAddress, int port) {
    mclientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mclientSocket == -1) {
        std::cerr << "Error while creating client socket\n";
        exit(EXIT_FAILURE);
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, ipAddress.c_str(), &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "Invalid IP Address\n";
        exit(EXIT_FAILURE);
    }
    int serverSocket = connect(mclientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if (serverSocket == -1) {
        std::cerr << "Error while connecting to Server\n";

        while (true) {
        std::string message;
        std::getline(std::cin,message);
        if (message == "exit") {
            break;
        }
        storeOfflineMessages(message);
        }
    }

    pthread_t thread;
    if (pthread_create(&thread, nullptr, RecieveMessages, (void*)this) != 0) {
        std::cerr << "Error creating thread\n";
        exit(EXIT_FAILURE);
    }

    pthread_detach(thread);

    sendStoredMessages();

    char buffer[256];
    while (true) {
        std::string message;
        std::getline(std::cin,message);
        if (message == "exit") {
            break;
        }
        SendToServer(message);
    }
}
 
void ClientSocket::DisConnect() {
    close(mclientSocket);
}

void ClientSocket::SendToServer(const std::string &message){
    send(mclientSocket, message.c_str(), message.size(), 0);
}

void ClientSocket::sendStoredMessages() {
    std::lock_guard<std::mutex> lock(mvectorMutex);
    for (const std::string& message : mClientOfflineMessages) {
        SendToServer(message);
    }
    mClientOfflineMessages.clear();
}
 
void ClientSocket::storeOfflineMessages(const std::string& message) {
    std::lock_guard<std::mutex> lock(mvectorMutex);
    mClientOfflineMessages.push_back(message);
}