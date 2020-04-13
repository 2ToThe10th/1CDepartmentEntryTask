//
// Created by 2ToThe10th on 13.04.2020.
//

#include <iostream>
#include "ServerMain.h"
#include "../TCPHelper.h"

namespace Server {

void ServerMain::StartServer(uint16_t port, unsigned number_of_thread) {
  socket_.Initialize(port);

  for (int i = 0; i < number_of_thread; ++i) {
    handlers_.emplace_back([this] {
      this->GameHandler();
    });
  }
}

void ServerMain::Close() {
  is_work_ = false;
  for (auto &handler: handlers_) {
    if (handler.joinable()) {
      handler.join();
    }
  }
}

void ServerMain::GameHandler() {
  while (is_work_) {
    ClientAction client_action = socket_.WaitForClientAction();
    if (client_action.IsClosed()) {
      situations_.erase(client_action.GetSocket());
    } else if (client_action.GetLetter() == Config::kStartSymbol) {
      auto new_situation = new ClientSituation(ReturnRandomWords());
      mutex_.lock();
      situations_[client_action.GetSocket()] = new_situation;
      mutex_.unlock();
      WriteString(client_action.GetSocket(), new_situation->GetCurrent());
    } else {
      mutex_.lock();
      auto iter = situations_.find(client_action.GetSocket());
      if (iter == situations_.end()) {
        continue;
      }
      ClientSituation* situation = iter->second;
      mutex_.unlock();
      if (situation->AddLetter(client_action.GetLetter())) {
        WriteString(client_action.GetSocket(), Config::kWinSocketMessage);
      } else if (situation->IsLose()) {
        WriteString(client_action.GetSocket(), Config::kLoseSocketMessage);
      } else {
        WriteString(client_action.GetSocket(), situation->GetCurrent());
      }
    }
  }
}

std::string ServerMain::ReturnRandomWords() {
  return "father";
}
}