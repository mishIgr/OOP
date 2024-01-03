//
// Created by mikhail on 27.11.23.
//

#include "game_pause.h"

GamePause::GamePause(IWindow* window, InReader* reader, IMenu* options_menu)
: window(window), reader(reader), options_menu(options_menu), pointer(0) {}

void GamePause::render() {
    if (this->reader == nullptr || this->window == nullptr)
        return;

    while (this->window->is_open()) {
        for (auto key: this->reader->get_commands()) {
            if (key.com == Close)
                this->window->close();
            if (key.com == Back)
                return;
            if (key.com == Up)
                this->pointer = (this->pointer - 1) % 2; // this->pointer = (this->pointer - 1) % 3;
            if (key.com == Down)
                this->pointer = (this->pointer + 1) % 2; // this->pointer = (this->pointer + 1) % 3;
            if (key.com == Enter) {
                if (this->pointer == 0)
                    return;
                if (this->pointer == 2)
                    this->window->close();
                else
                    this->options_menu->render();
            }
        }

        this->window->clear();

        // {"Continue", "Options", "Back to menu"}
        this->window->draw_texts({"Continue", "Options"},
                                 "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer);

        this->window->display();
    }
}
