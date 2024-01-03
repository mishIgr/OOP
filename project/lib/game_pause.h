//
// Created by mikhail on 27.11.23.
//

#ifndef PROJECT_GAME_PAUSE_H
#define PROJECT_GAME_PAUSE_H

#include "Menu/menu.h"
#include "window.h"
#include "Reader/reader.h"

class GamePause : public IMenu {

    IWindow* window;
    InReader* reader;
    IMenu* options_menu;
    unsigned pointer;

public:

    GamePause(IWindow*, InReader*, IMenu*);

    void render();

};

#endif //PROJECT_GAME_PAUSE_H
