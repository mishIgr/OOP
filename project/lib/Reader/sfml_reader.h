//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_SFML_READER_H
#define PROJECT_SFML_READER_H

#include "Reader/reader.h"
#include "SFML/Graphics.hpp"
#include "Reader/sfml_config_scheme.h"
#include <map>

class SFMLReader : public InReader {

    sf::RenderWindow& window;
    std::map<sf::Keyboard::Key, Commands> commands_move;
    std::map<sf::Keyboard::Key, Commands> commands_other;

public:

    SFMLReader(sf::RenderWindow&);

    std::vector<Key> get_commands(bool = false);
    std::vector<std::string> get_key_str();
    void reset_config();
    void update();

};

#endif //PROJECT_SFML_READER_H
