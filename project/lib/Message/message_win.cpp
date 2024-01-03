//
// Created by mikhail on 10.12.23.
//

#include "message_win.h"
#include "sstream"
#include "iostream"

MessageWin::MessageWin(Player& player) : player(player) {}

std::string MessageWin::get_message() {
    std::stringstream message;
    message << "Player win:\n\tPlayer xp: " << std::to_string(player.get_life())
    << "\n\tPlayer double_jump: " << std::to_string(player.get_double_jump()) << '\n';
    return message.str();
}
