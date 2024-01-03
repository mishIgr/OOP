//
// Created by mikhail on 10.12.23.
//

#include "message_new_game.h"
#include "sstream"
#include "iostream"

MessageNewGame::MessageNewGame(GameObject& game_object) : game_object(game_object) {}

std::string MessageNewGame::get_message() {
    std::stringstream message;
    message << "New game:\n\tField (width, height): " << std::to_string(game_object.field.get_width()) << ", "
                       << std::to_string(game_object.field.get_height()) << "\n\tPlayer coord: "
                       << std::to_string(game_object.manage.get_coord()[0]) << ", "
                       << std::to_string(game_object.manage.get_coord()[1]) << '\n';
    return message.str();
}