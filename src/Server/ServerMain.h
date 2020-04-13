//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_SERVERMAIN_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_SERVERMAIN_H_

#include <cstdint>
#include <map>
#include <mutex>
#include "TCPSocketServer.h"
#include "ClientSituation.h"
namespace Server {

class ServerMain {
 public:
  void StartServer(uint16_t port, unsigned number_of_thread);

  void Close();
 private:
  TCPSocketServer socket_;
  std::vector<std::thread> handlers_;
  bool is_work_ = true;
  std::map<int, ClientSituation*> situations_;
  std::mutex mutex_;

 private:
  void GameHandler();

  std::string ReturnRandomWords();
};

}

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_SERVERMAIN_H_
