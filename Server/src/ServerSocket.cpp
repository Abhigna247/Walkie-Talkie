#include "/home/kpit/Downloads/Walkie-Talkie/Server/api/ServerSocket.h"

#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <pthread.h>

ServerSocket::ServerSocket() : mserverSocket(-1), misServerActive(false) {
}
 
ServerSocket::~ServerSocket() {
    stop();
}
 
void ServerSocket::start(int port) {
    mserverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mserverSocket == -1) {
        std::cerr << "Error while creating server socket\n";
        exit(EXIT_FAILURE);
    }
 
    sockaddr_in serverAddress;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_family = AF_INET;

    if (bind(mserverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Binding to server socket failed\n";
        exit(EXIT_FAILURE);
    }

    listen(mserverSocket, 5);
    misServerActive = true;
    while (misServerActive) {
        int clientSocket = accept(mserverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Error while accepting the client\n";
        } else {
            std::cout << "Client connected\n";
            pthread_t send_thread, receive_thread;
            if (pthread_create(&send_thread, nullptr, &ServerSocket::SendingMessages, (void*)(&clientSocket)) != 0) {
                std::cerr << "Error creating thread\n";
                exit(EXIT_FAILURE);
            }

            pthread_detach(send_thread);
 
            if (pthread_create(&receive_thread, nullptr, &ServerSocket::RecieveMessages, (void*)(&clientSocket)) != 0) {
                std::cerr << "Error creating thread\n";
                exit(EXIT_FAILURE);
            }
            pthread_detach(receive_thread);

        }
    }
}
 
void ServerSocket::stop() {
    misServerActive = false;
    close(mserverSocket);
}
 
void* ServerSocket::SendingMessages(void* arg) {
    int clientSocket = *((int*)arg);
    while (true) {
        std::string response;
        std::getline(std::cin,response);
        if (response == "exit") {
            break;
        }

        send(clientSocket, response.c_str(), response.size(), 0);
    }
    close(clientSocket);
    return nullptr;
}
 
void* ServerSocket::RecieveMessages(void* arg) {
    int clientSocket = *((int*)arg);
    char buffer[256];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Connection closed by Client\n";
            break;
        }
        std::cout << "Client message: " << buffer << std::endl;
    }

    close(clientSocket);
    return nullptr;
}
 
void ServerSocket::SendStoredMessages(int clientSocket) {
    std::lock_guard<std::mutex> lock(mvectorMutex);
    for (const std::string& message : mServerOfflinemessages) {
        send(clientSocket, message.c_str(), message.size(), 0);
    }
   mServerOfflinemessages.clear();
}
 
void ServerSocket::storeOfflineMessage(const std::string& message) {
   std::lock_guard<std::mutex> lock(mvectorMutex);
   mServerOfflinemessages.push_back(message);
}
