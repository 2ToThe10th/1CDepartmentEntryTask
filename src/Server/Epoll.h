//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_EPOLL_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_EPOLL_H_

namespace Server {

class Epoll {
 public:
  Epoll();

  void Add(int socket);

  int WaitOne(uint32_t& epoll_event);

  ~Epoll();
 private:
  int epoll_fd_ = -1;
};

}

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_EPOLL_H_
