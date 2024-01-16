#include "/home/kpit/Downloads/Walkie-Talkie/Server/api/ServerSocket.h"


#include <iostream>
 
 int main()
 {
    int port;
    std::cout << "Enter the port Number: \n";
    std::cin>>port;

    ServerSocket serverSocketObject;

    serverSocketObject.start(port);
    
}