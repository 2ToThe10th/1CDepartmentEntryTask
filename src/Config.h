//
// Created by 2ToThe10th on 13.04.2020.
//

#ifndef INC_1CDEPARTMENTENTRYTASK_CONFIG_H_
#define INC_1CDEPARTMENTENTRYTASK_CONFIG_H_

#include <string>

struct Config {

static std::string kWelcomeMessage;
static std::string kByeMessage;
static constexpr uint32_t kNumberOfAttempts = 5;
static std::string kWinSocketMessage;
static std::string kLoseSocketMessage;
static std::string kWinMessage;
static std::string kLoseMessage;
static constexpr char kStartSymbol = char(127);

};

#endif //INC_1CDEPARTMENTENTRYTASK_CONFIG_H_
