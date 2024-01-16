#include "/home/kpit/Downloads/Walkie-Talkie/Client/api/ClientSocket.h"

 
int main() {
    std::string ipAddress;
    int port;
 
    std::cout << "Enter IP address: ";
    std::cin >> ipAddress;
 
    std::cout << "Enter port number: ";
    std::cin >> port;
 
    ClientSocket clientSocketObject;
    clientSocketObject.Connect(ipAddress, port);
 
 
    return 0;
}