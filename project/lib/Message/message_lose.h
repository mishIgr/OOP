//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_MESSAGE_LOSE_H
#define PROJECT_MESSAGE_LOSE_H

#include "message.h"
#include "Object/game_object.h"

class MessageLose : public Message {

    Manage& manage;

public:

    MessageLose(Manage&);

    std::string get_message();

};

#endif //PROJECT_MESSAGE_LOSE_H
