//
// Created by 2ToThe10th on 13.04.2020.
//


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#include "TCPSocketClient.h"
#include "../TCPHelper.h"

namespace Client {

TCPSocketClient::TCPSocketClient() = default;

void TCPSocketClient::Initialize(const std::string &host, uint16_t port) {
  socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_ < 0) {
    throw std::system_error(errno, std::generic_category());
  }

  struct sockaddr_in server_address{};
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);

  if (inet_aton(host.c_str(), &server_address.sin_addr) != 1) {
    throw InetAtonException();
  }

  if (connect(socket_, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
    throw std::system_error(errno, std::generic_category());
  }
}

std::string TCPSocketClient::Read() {
  uint8_t receive_size;
  ReadAll(socket_, reinterpret_cast<char *>(&receive_size), sizeof(receive_size));
  char receive_string[receive_size];
  ReadAll(socket_, receive_string, receive_size);
  return std::move(std::string(receive_string, receive_size));
}

void TCPSocketClient::WriteLetter(char letter) {
  WriteAll(socket_, &letter, 1);
}

TCPSocketClient::~TCPSocketClient() {
  shutdown(socket_, SHUT_RDWR);
  close(socket_);
}

}
