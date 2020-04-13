//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_TCPHELPER_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_TCPHELPER_H_

#include <cstdlib>
#include <exception>

class InetAtonException : public std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "inet aton";
  }
};

void WriteAll(int socket_fd, const char *buffer, size_t buffer_size);

void ReadAll(int socket_fd, char *buffer, size_t buffer_size);

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_TCPHELPER_H_
