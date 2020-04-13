cmake_minimum_required(VERSION 3.2)
project(1CDepartmentEntryTask)

set(CMAKE_CXX_STANDARD 17)

if (SERVER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSERVER")
endif ()

if (CLIENT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCLIENT")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCE_FILES src/main.cpp src/Client/ClientMain.cpp src/Client/ClientMain.h src/Client/TCPSocketClient.cpp src/Client/TCPSocketClient.h src/TCPHelper.cpp src/Config.h src/TCPHelper.h src/Server/ServerMain.cpp src/Server/ServerMain.h src/Server/TCPSocketServer.cpp src/Server/TCPSocketServer.h src/Server/Epoll.cpp src/Server/Epoll.h src/Server/ClientAction.cpp src/Server/ClientAction.h src/Server/ClientSituation.cpp src/Server/ClientSituation.h src/Config.cpp)

add_executable(1CDepartmentEntryTask ${SOURCE_FILES})