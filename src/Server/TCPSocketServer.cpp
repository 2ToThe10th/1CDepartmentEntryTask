//
// Created by 2ToThe10th on 13.04.2020.
//

#include "TCPSocketServer.h"
#include "../TCPHelper.h"
#include "ClientAction.h"
#include <sys/socket.h>
#include <sys/epoll.h>
#include <system_error>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

namespace Server {

void TCPSocketServer::Initialize(uint16_t port) {
  accept_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (accept_socket_ < 0) {
    throw std::system_error(errno, std::generic_category());
  }

  struct sockaddr_in addr = {
      .sin_family = AF_INET,
      .sin_port = htons(port),
  };

  if (inet_aton("127.0.0.1", &addr.sin_addr) != 1) {
    throw InetAtonException();
  }

  if (bind(accept_socket_, (struct sockaddr *) &addr, sizeof(addr)) != 0) {
    throw std::system_error(errno, std::generic_category());
  }

  if (listen(accept_socket_, 128) != 0) {
    throw std::system_error(errno, std::generic_category());
  }

  epoll_.Add(accept_socket_);
}

ClientAction TCPSocketServer::WaitForClientAction() {
  uint32_t epoll_event;

  for (;;) {
    int socket = epoll_.WaitOne(epoll_event);

    std::cout << "Wait " << socket << std::endl;

    if (socket == accept_socket_) {
      int new_client = accept(accept_socket_, nullptr, nullptr);
      std::cout << "New Client " << new_client << std::endl;
      epoll_.Add(new_client);
    } else {
      if (epoll_event == EPOLLHUP) {
        close(socket);
        return ClientAction::Closed();
      } else {
        std::cout << socket << std::endl;
        char letter;
//        try {
          ReadAll(socket, &letter, sizeof(char));
//        } catch (std::system_error& error) {
//          close(socket);
//          return ClientAction::Closed();
//        }
        return ClientAction::Action(socket, letter);
      }
    }
  }
}

}