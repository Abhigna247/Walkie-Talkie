#include "/home/kpit/Downloads/Walkie-Talkie/Server/api/ServerSocket.h"

#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <cstring>

ServerSocket::ServerSocket():mserverSocket(-1),misServerAcive(false){
}

ServerSocket::~ServerSocket()
{
    stop();
}

void ServerSocket::start(int port)
{
    mserverSocket = socket(AF_INET,SOCK_STREAM,0);
    if(mserverSocket == -1){
        std::cerr << "Error While creating serverSocket\n";
    }

    sockaddr_in serverAddress;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_family = AF_INET;

    if(bind(mserverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress))==-1){
        std::cerr << "Binding to server socket failed\n";
    }

    listen(mserverSocket,5);

    misServerAcive = true;

    ListenForClients();
}

void ServerSocket::stop(){
    misServerAcive = false;
    close(mserverSocket);
}

void ServerSocket::ListenForClients(){
    while (misServerAcive){
        int clientSocket = accept(mserverSocket,nullptr,nullptr);
        if(clientSocket == -1){
            std::cerr << "Error while Server connecting to the client\n";
        }  

    std::cout << "Client connected\n";

    HandleClients(clientSocket);

    }
}

void ServerSocket::HandleClients(int mClientSocket) {
    char buffer[256];
    while (true) {
        std::string message;
        std::cout << "Enter message (or 'exit' to quit): ";
        std::getline(std::cin, message);
        if (message == "exit") {
            break;
        }
        send(mserverSocket,message.c_str(),message.size(),0);
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(mClientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            std::cerr << "Connection closed by Client\n";
            break;
        }
        std::cout << "Client response: " << buffer << std::endl; 
    }
 
    close(mClientSocket);

}
