//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_SFML_CONFIG_SCHEME_H
#define PROJECT_SFML_CONFIG_SCHEME_H

#include "Reader/reader.h"
#include "SFML/Graphics.hpp"
#include <map>

class SFMLConfigScheme {

    std::map<sf::Keyboard::Key, Commands> to_command;

public:

    SFMLConfigScheme(bool = true);

    bool save();
    bool restore();
    std::map<sf::Keyboard::Key, Commands> get_map_to_command();
    void replace_key(sf::Keyboard::Key, Commands);

};

#endif //PROJECT_SFML_CONFIG_SCHEME_H
