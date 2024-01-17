#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <iostream>

class ClientSocket
{
private:
    int mclientSocket;
public:
    ClientSocket();
    ~ClientSocket();

    static void* RecieveMessages(void* arg); 
    void Connect(const std::string& ipAddress,int port);
    void DisConnect();
};

#endif // CLIENTSOCKET_H
