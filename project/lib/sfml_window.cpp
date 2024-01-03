//
// Created by mikhail on 19.11.23.
//

#include "sfml_window.h"
#include "Reader/sfml_reader.h"

SFMLWindow::SFMLWindow(sf::RenderWindow& window) : window(window) {}

bool SFMLWindow::is_open() { return this->window.isOpen(); }

void SFMLWindow::close() { this->window.close(); }

void SFMLWindow::clear() { this->window.clear(); }

void SFMLWindow::display() { this->window.display(); }

Vector2U SFMLWindow::get_size() {return { this->window.getSize().x, this->window.getSize().y }; }

std::vector<Key> SFMLWindow::poll_event() { return SFMLReader(this->window).get_commands(); }

void SFMLWindow::draw_texts(std::vector<std::string> captions, std::string loc_font, unsigned characterSize, unsigned marker) {
    this->draw_texts(captions, loc_font, characterSize, marker, {{0, 0}, {this->window.getSize().x, this->window.getSize().y}});
}

void SFMLWindow::draw_texts(std::vector<std::string> captions, std::string loc_font, unsigned characterSize, unsigned marker,
                            std::pair<std::pair<float, float>, std::pair<float, float>> area) {
    sf::Font font;
    font.loadFromFile(loc_font);
    for (size_t i = 0; i < captions.size(); ++i) {
        sf::Text text(captions[i], font, characterSize);
        text.setPosition(area.first.first + (area.second.first - area.first.first - text.getLocalBounds().width) / 2,
                         area.first.second + (area.second.second - area.first.second - characterSize * captions.size()) / 2 + (characterSize + 5) * i);
        if (i == marker)
            text.setFillColor(sf::Color::Green);

        this->window.draw(text);
    }
}


void SFMLWindow::draw_sprite(std::string loc_texture, std::pair<float, float> coord) {
    sf::Texture texture;
    texture.loadFromFile(loc_texture);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(coord.first, coord.second);
    this->window.draw(sprite);
}
