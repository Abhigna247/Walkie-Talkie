#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

class ServerSocket
{
private:
    int mserverSocket;
    bool misServerAcive;
public:
    ServerSocket();
    ~ServerSocket();

    void start(int port);

    void stop();

    void ListenForClients();

    void HandleClients(int mClientSocket);

};

#endif // SERVERSOCKET_H
