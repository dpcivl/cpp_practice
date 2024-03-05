cmake_minimum_required(VERSION 3.10)
project(TCP_IP_PROGRAMMING)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable for server
add_executable(Server server.cpp)

# Add executable for client
add_executable(Client client.cpp)
