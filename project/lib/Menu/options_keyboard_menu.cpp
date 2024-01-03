//
// Created by mikhail on 27.11.23.
//

#include "options_keyboard_menu.h"

OptionsKeyboardMenu::OptionsKeyboardMenu(IWindow* window, InReader* reader, IChangeMenu* change_menu)
: window(window), reader(reader), change_menu(change_menu), pointer(0) {}

void OptionsKeyboardMenu::render() {
    if (this->reader == nullptr || this->window == nullptr || this->change_menu == nullptr)
        return;

    while (this->window->is_open()) {
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

        for (auto key: this->reader->get_commands()) {
            if (key.com == Close)
                this->window->close();
            else if (key.com == Back)
                return;
            else if (key.com == Up)
                this->pointer = (this->pointer + menu_items.size() - 1) % menu_items.size();
            else if (key.com == Down)
                this->pointer = (this->pointer + 1) % menu_items.size();
            else if (key.com == Enter) {
                if (this->pointer == 12)
                    this->reader->reset_config();
                else
                    this->change_menu->reset(static_cast<Commands>(this->pointer));
            }
        }

        this->window->clear();


        this->window->draw_texts(menu_items,
                           "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer);

        this->window->display();
    }
}
