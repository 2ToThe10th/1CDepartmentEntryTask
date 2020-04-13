//
// Created by 2ToThe10th on 13.04.2020.
//


#include <iostream>
#include "Client/ClientMain.h"
#include "Server/ServerMain.h"

int main(int argc, char* argv[]) {
#ifdef SERVER
  if (argc != 2) {
    std::cout << "You need to write port to bind" << std::endl;
    return 1;
  }

  Server::ServerMain server;

  server.StartServer(strtoul(argv[1], nullptr, 10), 1);// strtoul(argv[2], nullptr, 10));

  char t;
  std::cin >> t;

  server.Close();
#endif
#ifdef CLIENT
  if (argc != 3) {
    std::cout << "You need to write host and port to connect" << std::endl;
    return 1;
  }

  Client::ClientMain client;

  client.StartGame(argv[1], strtoul(argv[2], nullptr, 10));
#endif
}