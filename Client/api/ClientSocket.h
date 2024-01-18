#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <iostream>
#include <mutex>
#include <vector>

/**
 * ClientSocket class creates a socket to connect with the server 
 * And whenever the server is available to listen the connection it directly communicates with it
 * And when the server goes to offline then it stores the messages in the vector and when it comes to online
 * it will send those messages And when it goes offline After coming to online it will check the vector of the server
 * And retrives those messages before sending new ones.
*/

class ClientSocket
{
private:
    int mclientSocket;
    std::mutex mvectorMutex;
    std::vector<std::string> mClientOfflineMessages;

public:
    /**
     * Constuctor
    */
    ClientSocket();

    /**
     * destructor
    */
    ~ClientSocket();

    /**
     * it send the messages to the server and runs as a seperate thread
     * @param: it takes a pointer to the agument
    */
    static void* RecieveMessages(void* arg); 

    /**
     * it creates a clent socket to listen to server connections and connect when server is available
     * @param: ipaddress of the server
     *         port number of the server
    */
    void Connect(const std::string& ipAddress,int port);

    /**
     * it closes the clientsocket
    */
    void DisConnect();

    /**
     * it send te message to the server
     * @param: message to send
    */
    void SendToServer(const std::string& message);

    /**
     * it send the mesages stored in the vector to the server when it comes online
    */
    void sendStoredMessages();

    /**
     * it stores the messages to be sent when the client is in offline
     * @param: message of string type
    */
    void storeOfflineMessages(const std::string& message);
};

#endif // CLIENTSOCKET_H
