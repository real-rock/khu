cmake_minimum_required(VERSION 3.21)
project(server)

set(CMAKE_CXX_STANDARD 20)

add_executable(server main.cpp socket.cpp worker.cpp)

target_include_directories(server PUBLIC ${CMAKE_SOURCE_DIR}/)