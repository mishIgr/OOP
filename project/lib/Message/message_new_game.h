//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_MESSAGE_NEW_GAME_H
#define PROJECT_MESSAGE_NEW_GAME_H

#include "message.h"
#include "Object/game_object.h"

class MessageNewGame : public Message {

    GameObject game_object;

public:

    MessageNewGame(GameObject&);

    std::string get_message();

};

#endif //PROJECT_MESSAGE_NEW_GAME_H
