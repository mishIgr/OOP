//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_MAIN_MENU_H
#define PROJECT_MAIN_MENU_H

#include "menu.h"
#include "reader.h"
#include "window.h"
#include "draw_text.h"
#include "options_menu.h"
#include "game.h"
#include <map>

template<typename Window>
class MainMenu : public IMenu {

    unsigned pointer;
    IWindow<Window>* window;
    InReader* reader;
    IMenu* game;

public:

    MainMenu(IWindow<Window>*, InReader*, IMenu*);

    void render();

};

template<typename Window>
MainMenu<Window>::MainMenu(IWindow<Window>* window, InReader* reader, IMenu* game) :
window(window), reader(reader), game(game), pointer(0) {}

template<typename Window>
void MainMenu<Window>::render() {
    if (this->reader == nullptr || this->window == nullptr || this->game == nullptr)
        return;

    std::map<unsigned, IMenu*> to_menu {
            {0, this->game},
            {1, new OptionsMenu(this->window, this->reader)}
    };

    while (this->window->get_window().isOpen()) {
        for (auto com: this->reader->get_commands()) {
            if (com == Close || com == Back)
                this->window->get_window().close();
            if (com == Up)
                this->pointer = (this->pointer - 1) % 2;
            if (com == Down)
                this->pointer = (this->pointer + 1) % 2;
            if (com == Enter) {
                if (to_menu[this->pointer] != nullptr)
                    to_menu[this->pointer]->render();
            }
        }

        this->window->get_window().clear();

        DrawText(this->window, {"Play", "Options"}, "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer);

        this->window->get_window().display();
    }

    for (auto& item : to_menu)
        delete item.second;

}

#endif //PROJECT_MAIN_MENU_H
