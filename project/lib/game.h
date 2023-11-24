#ifndef game_h
#define game_h

#include "menu.h"
#include "reader.h"
#include "window.h"
#include "sfml_field_render.h"
#include "File_manager/file_manager.h"
#include <map>
#include <iostream>

template<typename Window>
class Game : public IMenu {

    IWindow<Window>* window;
    InReader* reader;

public:

    Game(IWindow<Window>*, InReader*);

    void render();

};

template<typename Window>
Game<Window>::Game(IWindow<Window>* window, InReader* reader) : window(window), reader(reader) {}

template<typename Window>
void Game<Window>::render() {
    if (this->reader == nullptr || this->window == nullptr)
        return;

    Player player;
    Field field;
    Manage manage(player, field);
    if (!FileMahager().read_bin("/home/mikhail/OOP_lab/project/bin/level/level1.bin", field, player, manage))
        return;

    std::map<Commands, Direct> to_direct {
            {Up, UP},
            {Down, DOWN},
            {Left, LEFT},
            {Right, RIGHT},
            {DUp, D_UP},
            {DDown, D_DOWN},
            {DLeft, D_LEFT},
            {DRight, D_RIGHT}
    };

    bool update = true;
    this->window->get_window().clear();
    while (this->window->get_window().isOpen()) {
        for (auto com: this->reader->get_commands()) {
            if (com == Back)
                return;
            if (com == Close)
                this->window->get_window().close();
            else if (com == Restart) {
                if (!FileMahager().read_bin("/home/mikhail/OOP_lab/project/bin/level/level2.bin", field, player, manage))
                    return;
                update = true;
            }
            else {
                auto p = to_direct.find(com);
                if (p != to_direct.end()) {
                    manage.move(to_direct[com]);
                    update = true;
                }
            }
        }

        if (update) {
            this->window->get_window().clear();

            SFMLRenderField(window, field, manage).draw();

            this->window->get_window().display();
        }
//        update = false;
    }
}

#endif