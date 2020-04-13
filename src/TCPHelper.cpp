//
// Created by 2ToThe10th on 13.04.2020.
//


#include <system_error>
#include <sys/socket.h>
#include <unistd.h>
#include "TCPHelper.h"

void WriteAll(int socket_fd, const char *buffer, size_t buffer_size) {
  size_t already_written = 0;
  while (buffer_size > 0) {
    int was_written = send(socket_fd, buffer + already_written, buffer_size, MSG_NOSIGNAL);
    if (was_written < 0) {
      throw std::system_error(errno, std::generic_category());
    }
    already_written += was_written;
    buffer_size -= was_written;
  }
}

void WriteString(int socket_fd, const std::string& buffer) {
  uint8_t size_to_send = buffer.size();
  WriteAll(socket_fd,
           reinterpret_cast<const char *>(&size_to_send),
           1);
  WriteAll(socket_fd,
           buffer.c_str(),
           buffer.size());
}

void ReadAll(int socket_fd, char *buffer, size_t buffer_size) {
  size_t already_read = 0;
  while (buffer_size > 0) {
    int was_read = read(socket_fd, buffer + already_read, buffer_size);
    if (was_read < 0) {
      throw std::system_error(errno, std::generic_category());
    }
    already_read += was_read;
    buffer_size -= was_read;
  }
}
