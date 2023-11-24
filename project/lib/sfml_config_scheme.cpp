//
// Created by mikhail on 19.11.23.
//

#include "sfml_config_scheme.h"
#include "File_manager/file_manager.h"
#define FILE "/home/mikhail/OOP_lab/project/bin/keyboard/keyboard.bin"

SFMLConfigScheme::SFMLConfigScheme(bool flag_restore) : to_command{
        {sf::Keyboard::Q, Close},
        {sf::Keyboard::Escape, Back},
        {sf::Keyboard::Enter, Enter},
        {sf::Keyboard::R, Restart},
        {sf::Keyboard::Up, Up},
        {sf::Keyboard::Down, Down},
        {sf::Keyboard::Left, Left},
        {sf::Keyboard::Right, Right},
        {sf::Keyboard::W, DUp},
        {sf::Keyboard::S, DDown},
        {sf::Keyboard::A, DLeft},
        {sf::Keyboard::D, DRight}
} { if (flag_restore) this->restore(); }

bool SFMLConfigScheme::save() {
    std::string save_keyboard = "";

    for (size_t i = 0; i < this->to_command.size(); ++i) {
        sf::Keyboard::Key tmp;
        for (const auto &item: this->to_command)
            if (item.second == i)
                tmp = item.first;
        save_keyboard += std::string(reinterpret_cast<const char *>(&tmp), sizeof(tmp));
    }

    if (!FileMahager().write_bin(FILE, save_keyboard))
        return false;

    return true;
}

bool SFMLConfigScheme::restore() {
    std::string save_keyboard = "";
    if (!FileMahager().read_bin(FILE, save_keyboard))
        return false;

    std::map<sf::Keyboard::Key, Commands> new_to_command;
    for (unsigned i = 0; !save_keyboard.empty(); ++i) {
        new_to_command[*reinterpret_cast<const sf::Keyboard::Key *>
        (save_keyboard.substr(0, sizeof(sf::Keyboard::Key)).c_str())] = static_cast<Commands>(i);
        save_keyboard = save_keyboard.substr(sizeof(sf::Keyboard::Key));
    }

    this->to_command = std::move(new_to_command);

    return true;
}

std::map<sf::Keyboard::Key, Commands> SFMLConfigScheme::get_map_to_command() { return this->to_command; }

void SFMLConfigScheme::replace_key(sf::Keyboard::Key key, Commands value) {
    auto tmp = this->to_command.find(key);
    if (tmp != this->to_command.end())
        return;

    sf::Keyboard::Key delete_key;
    for (const auto& item : this->to_command)
        if (item.second == value)
            delete_key = item.first;
    this->to_command.erase(delete_key);
    this->to_command[key] = value;
}
