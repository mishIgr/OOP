//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_OPTIONS_MENU_H
#define PROJECT_OPTIONS_MENU_H

#include "menu.h"
#include "reader.h"
#include "window.h"
#include "keyboard.h"
#include "draw_text.h"
#include "sfml_change_key_menu.h"
#include <map>

template<typename Window>
class OptionsMenu : public IMenu {

    unsigned pointer;
    IWindow<Window>* window;
    InReader* reader;

public:

    OptionsMenu(IWindow<Window>*, InReader*);

    void render();

};

template<typename Window>
OptionsMenu<Window>::OptionsMenu(IWindow<Window>* window, InReader* reader) : window(window), reader(reader), pointer(0) {}

template<typename Window>
void OptionsMenu<Window>::render() {
    if (this->reader == nullptr || this->window == nullptr)
        return;

    while (this->window->get_window().isOpen()) {
        std::vector<std::string> key_config = this->reader->get_key_str();

        std::vector<std::string> menu_items {"Closing key: " + key_config[0],
                                             "Action selection key: " + key_config[1],
                                             "Backspace key: " +  key_config[2],
                                             "Restarting key: " +  key_config[3],
                                             "Move up key: " +  key_config[4],
                                             "Move down key: " +  key_config[5],
                                             "Move left key: " +  key_config[6],
                                             "Move right key: " +  key_config[7],
                                             "Move double up key: " +  key_config[8],
                                             "Move double down key: " +  key_config[9],
                                             "Move double left key: " +  key_config[10],
                                             "Move double right key: " +  key_config[11],
                                             "Default settings"};

        for (auto com: this->reader->get_commands()) {
            if (com == Close)
                this->window->get_window().close();
            else if (com == Back)
                return;
            else if (com == Up)
                this->pointer = (this->pointer + menu_items.size() - 1) % menu_items.size();
            else if (com == Down)
                this->pointer = (this->pointer + 1) % menu_items.size();
            else if (com == Enter) {
                if (this->pointer == 12)
                    this->reader->reset_config();
                else
                    SFMLChangeKeyMenu(this->window, this->reader).reset(static_cast<Commands>(this->pointer));
            }
        }

        this->window->get_window().clear();

        DrawText(this->window, menu_items,
                 "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer);

        this->window->get_window().display();
    }
}

#endif //PROJECT_OPTIONS_MENU_H
