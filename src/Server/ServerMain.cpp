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
    std::cout << "HERE " << client_action.GetSocket() << std::endl;
    if (client_action.IsClosed()) {
      std::cout << "HERE Erase" << client_action.GetSocket() << std::endl;
      situations_.erase(client_action.GetSocket());
    } else if (client_action.GetLetter() == Config::kStartSymbol) {
      std::cout << "HERE Ok" << client_action.GetSocket() << std::endl;
      auto new_situation = new ClientSituation(ReturnRandomWords());
      mutex_.lock();
      situations_[client_action.GetSocket()] = new_situation;
      mutex_.unlock();
      uint8_t size_to_send = new_situation->GetCurrent().size();
      WriteAll(client_action.GetSocket(),
               reinterpret_cast<const char *>(&size_to_send),
               1);
      WriteAll(client_action.GetSocket(),
               new_situation->GetCurrent().c_str(),
               new_situation->GetCurrent().size());
      WriteAll(client_action.GetSocket(),
               new_situation->GetCurrent().c_str(),
               new_situation->GetCurrent().size());
      std::cout << "HERE Send" << client_action.GetSocket() << std::endl;
    } else {
      mutex_.lock();
      auto iter = situations_.find(client_action.GetSocket());
      if (iter == situations_.end()) {
        continue;
      }
      ClientSituation situation = *iter->second;
      mutex_.unlock();
      if (situation.AddLetter(client_action.GetLetter())) {
        uint8_t size_to_send = Config::kWinSocketMessage.size();
        WriteAll(client_action.GetSocket(),
                 reinterpret_cast<const char *>(&size_to_send),
                 1);
        WriteAll(client_action.GetSocket(),
                 Config::kWinSocketMessage.c_str(),
                 Config::kWinSocketMessage.size());
      } else if (situation.IsLose()) {
        uint8_t size_to_send = Config::kLoseSocketMessage.size();
        WriteAll(client_action.GetSocket(),
                 reinterpret_cast<const char *>(&size_to_send),
                 1);
        WriteAll(client_action.GetSocket(),
                 Config::kLoseSocketMessage.c_str(),
                 Config::kLoseSocketMessage.size());
      } else {
        uint8_t size_to_send = situation.GetCurrent().size();
        WriteAll(client_action.GetSocket(),
                 reinterpret_cast<const char *>(&size_to_send),
                 1);
        WriteAll(client_action.GetSocket(),
                 situation.GetCurrent().c_str(),
                 situation.GetCurrent().size());
      }
    }
  }
}

std::string ServerMain::ReturnRandomWords() {
  return "father";
}
}