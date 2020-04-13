//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_CLIENTMAIN_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_CLIENTMAIN_H_

#include "TCPSocketClient.h"
namespace Client {

class ClientMain {
 public:
  ClientMain();

  void StartGame(const std::string &host, uint16_t port);

 private:
  TCPSocketClient socket_;

 private:
  void PlayOneGame();
};

}

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_CLIENTMAIN_H_
