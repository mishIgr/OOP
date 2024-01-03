//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_OPTIONS_KEYBOARD_MENU_H
#define PROJECT_OPTIONS_KEYBOARD_MENU_H

#include "Menu/menu.h"
#include "Reader/reader.h"
#include "window.h"
#include "Reader/keyboard.h"
#include "Menu/change_key_menu.h"
#include <map>

class OptionsKeyboardMenu : public IMenu {

    unsigned pointer;
    IWindow* window;
    InReader* reader;
    IChangeMenu* change_menu;

public:

    OptionsKeyboardMenu(IWindow*, InReader*, IChangeMenu*);

    void render();

};

#endif //PROJECT_OPTIONS_KEYBOARD_MENU_H
