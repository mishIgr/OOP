//
// Created by mikhail on 10.12.23.
//

#include "message_keyboard_push.h"
#include "sstream"
#include "iostream"
#include "Reader/sfml_config_scheme.h"

std::string MessageKeyboardPush::get_message() {
    std::stringstream message;
    message << "Keyboard " << this->key.keyboard << " push, ";

    auto to_command = SFMLConfigScheme().get_map_to_command();
    bool in_scheme = false;
    for (auto& el : to_command) {
        if (this->key.com == el.second) {
            in_scheme = true;
            break;
        }
    }
    if (!in_scheme) {
        message << "none of commands worked\n";
        return message.str();
    }

    std::string com;
    auto it = this->com_str.find(this->key.com);
    if (it == this->com_str.end())
        com = "not defined\n";
    else
        com = it->second;
    message << "the command worked " << com << '\n';
    return message.str();
}

void MessageKeyboardPush::update(Key key) { this->key = key; }