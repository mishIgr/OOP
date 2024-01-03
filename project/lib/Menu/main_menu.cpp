//
// Created by mikhail on 27.11.23.
//

#include "main_menu.h"

MainMenu::MainMenu(IWindow* window, InReader* reader, Game* game, IMenu* options_keyboard_menu, IMenu* options_logger_menu) :
        window(window), reader(reader), game(game), options_keyboard_menu(options_keyboard_menu),
        options_logger_menu(options_logger_menu), pointer(0) {}

void MainMenu::render() {
    if (this->reader == nullptr || this->window == nullptr || this->game == nullptr
    || this->options_keyboard_menu == nullptr || this->options_logger_menu == nullptr)
        return;

    while (this->window->is_open()) {
        for (auto key: this->reader->get_commands()) {
            if (key.com == Close || key.com == Back)
                this->window->close();
            else if (key.com == Up)
                this->pointer = (this->pointer + 2) % 3;
            else if (key.com == Down)
                this->pointer = (this->pointer + 1) % 3;
            else if (key.com == Enter) {
                if (this->pointer == 0)
                    this->game->render();
                else if (this->pointer == 1)
                    this->options_keyboard_menu->render();
                else
                    this->options_logger_menu->render();
            }
        }

        this->window->clear();

        this->window->draw_texts({"Play", "Options keyboard", "Options logger"},
                           "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer);

        this->window->display();
    }
}
