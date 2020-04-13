//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_TCPSOCKETSERVER_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_TCPSOCKETSERVER_H_

#include <cstdint>
#include <thread>
#include <vector>
#include "Epoll.h"
#include "ClientAction.h"
namespace Server {

class TCPSocketServer {
 public:
  void Initialize(uint16_t port);

  ClientAction WaitForClientAction();

 private:
  Epoll epoll_;
  int accept_socket_ = -1;
};

}

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_TCPSOCKETSERVER_H_
