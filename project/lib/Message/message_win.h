//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_MESSAGE_WIN_H
#define PROJECT_MESSAGE_WIN_H

#include "message.h"
#include "Object/game_object.h"

class MessageWin : public Message {

    Player& player;

public:

    MessageWin(Player&);

    std::string get_message();

};

#endif //PROJECT_MESSAGE_WIN_H
