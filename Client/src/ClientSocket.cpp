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
    clientSocket->RecieveMessages();
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
        exit(EXIT_FAILURE);
    }
 
    pthread_t thread;
    if (pthread_create(&thread, nullptr, RecieveMessages, (void*)this) != 0) {
        std::cerr << "Error creating thread\n";
        exit(EXIT_FAILURE);
    }

    pthread_detach(thread);
    char buffer[256];
    while (true) {
        std::string message;
        std::cout << "Enter message (or 'exit' to quit): ";
        std::getline(std::cin, message);
        if (message == "exit") {
            break;
        }
        send(mclientSocket, message.c_str(), message.size(), 0);
    }
}
 
void ClientSocket::DisConnect() {
    close(mclientSocket);
}
 
void ClientSocket::RecieveMessages() {
    char buffer[256];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(mclientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Connection closed by server\n";
            break;
        }
        std::cout << "Server message: " << buffer << std::endl;
    }
}

