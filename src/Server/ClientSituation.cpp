//
// Created by 2ToThe10th on 13.04.2020.
//

#include <iostream>
#include "ClientSituation.h"
ClientSituation::ClientSituation(std::string to_guess): to_guess_(std::move(to_guess)) {
  current_.resize(to_guess_.size(), '*');
}
const std::string & ClientSituation::GetCurrent() {
  return current_;
}
bool ClientSituation::AddLetter(char letter) {
  bool is_win = true;
  bool is_changed = false;
  for (int i = 0; i < to_guess_.size(); ++i) {
    if (to_guess_[i] == letter && current_[i] == '*') {
      current_[i] = letter;
      is_changed = true;
    }
    if (current_[i] == '*') {
      is_win = false;
    }
  }
  if (!is_changed) {
    --number_of_attempts_;
  }
  return is_win;
}

bool ClientSituation::IsLose() {
  return number_of_attempts_ <= 0;
}
