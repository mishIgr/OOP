//
// Created by mikhail on 10.12.23.
//

#include "message_lose.h"
#include "sstream"
#include "iostream"

MessageLose::MessageLose(Manage& manage) : manage(manage) {}

std::string MessageLose::get_message() {
    std::stringstream message;
    message << "Player lose in cell: " << std::to_string(manage.get_coord()[0])
    << ", " << std::to_string(manage.get_coord()[1]) << '\n';
    return message.str();
}
