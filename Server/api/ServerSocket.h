#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <mutex>
#include <iostream>
#include <vector>

/**
 * ServerSocket class creates a socket to connect with the listening client 
 * And whenever the client is available to listen the connection then it directly communicates with it
 * And when the client goes to offline then it stores the messages in the vector and when it comes to online
 * it will send those messages And when it goes offline After coming to online it will check the vector of the Client
 * And retrives those messages before sending new ones.
*/

class ServerSocket
{
private:
    int mserverSocket;
    bool misServerActive;
    std::mutex mvectorMutex;
    std::vector<std::string> mServerOfflinemessages;

public:
    /**
     * default constructor
    */
    ServerSocket();

    /**
     * dstructor
    */
    ~ServerSocket();

    /**
     * it creates a socket and binds the local address to it and then listen for the conection
     * @param: port number
    */
    void start(int port);

    /**
     * closes the server socket
    */
    void stop();

    /**
     * it send the messages to the client and runs as a seperate thread
     * @param: it takes a pointer to the agument
    */
    static void* SendingMessages(void* arg);

    /**
     * it recieves the messages from the client and runs as aseperate thread
     * @param: it takes a pointer to the agument
    */
    static void* RecieveMessages(void* arg);

    /**
     * it send the mesages stored in the vector to the client when it comes online
     * @param: client socket descriptor
    */
    void SendStoredMessages(int clientSocket);

    /**
     * it stores the messages to be sent when the client is in offline
     * @param: message of string type
    */
    void storeOfflineMessage(const std::string& message);

};

#endif // SERVERSOCKET_H
