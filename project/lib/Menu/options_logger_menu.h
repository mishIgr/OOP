//
// Created by mikhail on 11.12.23.
//

#ifndef PROJECT_OPTIONS_LOGGER_MENU_H
#define PROJECT_OPTIONS_LOGGER_MENU_H

#include "menu.h"
#include "Reader/reader.h"
#include "window.h"
#include "logger.h"
#include "game.h"
#include <map>

class OptionsLoggerMenu : public IMenu {

    unsigned pointer;
    IWindow* window;
    InReader* reader;
    Logger* logger;
    std::vector<Stream*> possible_streams;

public:

    OptionsLoggerMenu(IWindow*, InReader*, Logger*, std::vector<Stream*>);

    void render();

};

#endif //PROJECT_OPTIONS_LOGGER_MENU_H
