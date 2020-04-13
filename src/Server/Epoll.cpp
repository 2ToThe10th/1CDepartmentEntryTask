//
// Created by 2ToThe10th on 13.04.2020.
//

#include <sys/epoll.h>
#include <system_error>
#include <unistd.h>

#include "Epoll.h"

namespace Server {

Epoll::Epoll() {
  epoll_fd_ = epoll_create(1);
  if (epoll_fd_ < 0) {
    throw std::system_error(errno, std::generic_category());
  }
}

void Epoll::Add(int socket) {
  struct epoll_event event{};
  event.events = EPOLLIN;
  event.data.fd = socket;
  if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, socket, &event) < 0) {
    throw std::system_error(errno, std::generic_category());
  }
}

int Epoll::WaitOne(uint32_t& epoll_event) {
  struct epoll_event event{};
  epoll_wait(epoll_fd_, &event, 1, -1);
  epoll_event = event.events;
  return event.data.fd;
}

Epoll::~Epoll() {
  close(epoll_fd_);
}
}