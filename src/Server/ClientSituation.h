//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTSITUATION_H_
#define INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTSITUATION_H_

#include <string>
#include "../Config.h"
class ClientSituation {
 public:
  explicit ClientSituation(std::string to_guess);

  const std::string & GetCurrent();

  bool AddLetter(char letter);

  bool IsLose();
 private:
  std::string to_guess_;
  std::string current_;
  uint32_t number_of_attempts_ = Config::kNumberOfAttempts;
};

#endif //INC_1CDEPARTMENTENTRYTASK_SRC_SERVER_CLIENTSITUATION_H_
