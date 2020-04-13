//
// Created by 2ToThe10th on 13.04.2020.
//

#include "ClientAction.h"
ClientAction::ClientAction(int socket, char letter, bool is_close)
    : socket_(socket), letter_(letter), is_close_(is_close) {

}

ClientAction ClientAction::Closed() {
  return ClientAction(-1, '0', true);
}

ClientAction ClientAction::Action(int socket, char letter) {
  return ClientAction(socket, letter, false);
}

bool ClientAction::IsClosed() {
  return is_close_;
}

int ClientAction::GetSocket() {
  return socket_;
}

char ClientAction::GetLetter() {
  return letter_;
}
