//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_MAIN_MENU_H
#define PROJECT_MAIN_MENU_H

#include "menu.h"
#include "Reader/reader.h"
#include "window.h"
#include "game.h"
#include <map>

class MainMenu : public IMenu {

    unsigned pointer;
    IWindow* window;
    InReader* reader;
    Game* game;
    IMenu* options_keyboard_menu;
    IMenu* options_logger_menu;

public:

    MainMenu(IWindow*, InReader*, Game*, IMenu*, IMenu*);

    void render();

};

#endif //PROJECT_MAIN_MENU_H
