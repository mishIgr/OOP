//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_MESSAGE_KEYBOARD_PUSH_H
#define PROJECT_MESSAGE_KEYBOARD_PUSH_H

#include "message.h"
#include <map>
#include "Reader/reader.h"

class MessageKeyboardPush : public Message {

    const std::map<Commands, std::string> com_str {
            {Close, "Close"},
            {Enter, "Enter"},
            {Back, "Back"},
            {Restart, "Restart"},
            {Up, "Up"},
            {Down, "Down"},
            {Left, "Left"},
            {Right, "Right"},
            {DUp, "DUp"},
            {DDown, "DDown"},
            {DLeft, "DLeft"},
            {DRight, "DRight"}
    };
    Key key;

public:

    std::string get_message();
    void update(Key);

};

#endif //PROJECT_MESSAGE_KEYBOARD_PUSH_H
