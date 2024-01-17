cmake_minimum_required(VERSION 3.10) 
project(ClientApp)
set(CMAKE_CXX_STANDARD 11)
 
find_package(Threads REQUIRED)

# Server source files
file(GLOB_RECURSE SERVER_SOURCES "src/*.cpp")
 
add_executable(ClientMain ${SERVER_SOURCES} )

target_link_libraries(ClientMain PRIVATE Threads::Threads)


