//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_TCPSOCKETCLIENT_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_TCPSOCKETCLIENT_H_

#include <string>
namespace Client {

class TCPSocketClient {
 public:
  TCPSocketClient();

  void Initialize(const std::string &host, uint16_t port);

  std::string Read();

  void WriteLetter(char letter);

  ~TCPSocketClient();
 private:
  int socket_ = -1;
};

}

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_CLIENT_TCPSOCKETCLIENT_H_
