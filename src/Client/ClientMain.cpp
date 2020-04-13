//
// Created by 2ToThe10th on 13.04.2020.
//

#include <iostream>

#include "ClientMain.h"
#include "../Config.h"
namespace Client {

ClientMain::ClientMain() = default;

void ClientMain::StartGame(const std::string &host, uint16_t port) {
  socket_.Initialize(host, port);

  std::cout << Config::kWelcomeMessage << std::endl;

  while (true) {
    PlayOneGame();
    std::cout << "Do you want to play one more game?[Y/N]" << std::endl;
    std::string user_answer;
    std::cin >> user_answer;
    if (user_answer[0] != 'y' && user_answer[0] != 'Y') {
      std::cout << Config::kByeMessage << std::endl;
      break;
    }
  }
}

void ClientMain::PlayOneGame() {
  socket_.WriteLetter(Config::kStartSymbol);

  for (;;) {
    std::string read_message = socket_.Read();
    if (read_message == Config::kWinSocketMessage) {
      std::cout << Config::kWinMessage;
      break;
    }
    if (read_message == Config::kLoseSocketMessage) {
      std::cout << Config::kLoseMessage << std::endl;
      break;
    }
    std::cout << read_message << std::endl;


    std::string user_answer;
    std::cin >> user_answer;

    socket_.WriteLetter(user_answer[0]);
  }
}

}