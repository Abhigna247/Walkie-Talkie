cmake_minimum_required(VERSION 3.10) 
project(ServerApp)
set(CMAKE_CXX_STANDARD 11)

# Server source files
file(GLOB_RECURSE SERVER_SOURCES "src/*.cpp")
 
add_executable(ServerMain ${SERVER_SOURCES})
                                        