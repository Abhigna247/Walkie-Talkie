#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

class ServerSocket
{
private:
    int mserverSocket;
    bool misServerActive;
public:
    ServerSocket();
    ~ServerSocket();

    void start(int port);

    void stop();

    static void* clientThread(void* arg); 

};

#endif // SERVERSOCKET_H
