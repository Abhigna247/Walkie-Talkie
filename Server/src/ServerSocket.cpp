#include "/home/kpit/Downloads/Walkie-Talkie/Server/api/ServerSocket.h"

#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <pthread.h>

ServerSocket::ServerSocket() : mserverSocket(-1), misServerActive(false)
{
}

ServerSocket::~ServerSocket()
{
    stop();
}

void ServerSocket::start(int port)
{
    mserverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mserverSocket == -1)
    {
        std::cerr << "Error while creating server socket\n";
        exit(EXIT_FAILURE);
    }
    sockaddr_in serverAddress;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_family = AF_INET;
    if (bind(mserverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        std::cerr << "Binding to server socket failed\n";
        exit(EXIT_FAILURE);
    }

    listen(mserverSocket, 5);
    misServerActive = true;
    while (misServerActive)
    {
        int clientSocket = accept(mserverSocket, nullptr, nullptr);
        if (clientSocket == -1)
        {
            std::cerr << "Error while Server connecting to the client\n";
        }
        else
        {
            std::cout << "Client connected\n";
            pthread_t thread;
            if (pthread_create(&thread, nullptr, &ServerSocket::clientThread, (void *)(&clientSocket)) != 0)
            {
                std::cerr << "Error creating thread\n";
                exit(EXIT_FAILURE);
            }

            pthread_detach(thread);
        }
    }
}

void ServerSocket::stop()
{

    misServerActive = false;
    close(mserverSocket);
}

void *ServerSocket::clientThread(void *arg)
{
    int clientSocket = *((int *)arg);
    char buffer[256];
    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0)
        {
            std::cerr << "Connection closed by Client\n";
            break;
        }
        std::cout << "Client message: " << buffer << std::endl;
        std::string response;
        std::cout << "Enter response (or 'exit' to quit): ";
        std::getline(std::cin, response);
        if (response == "exit")
        {
            break;
        }

        send(clientSocket, response.c_str(), response.size(), 0);
    }

    close(clientSocket);
    return nullptr;
}
