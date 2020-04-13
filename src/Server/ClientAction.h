//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTACTION_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTACTION_H_

class ClientAction {
 public:
  ClientAction() = default;

  static ClientAction Closed();

  static ClientAction Action(int socket, char letter);

  bool IsClosed();

  int GetSocket();

  char GetLetter();
 private:
  ClientAction(int socket, char letter, bool is_close);

  int socket_ = -1;
  char letter_ = '0';
  bool is_close_ = false;

};

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTACTION_H_
