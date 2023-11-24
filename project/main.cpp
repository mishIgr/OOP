#include <iostream>
#include "lib/lib_game.h"
#include "SFML/Graphics.hpp"

void draw_wall(Field& field) {
    for (unsigned y = 0; y < field.get_height(); ++y) {
        for (unsigned x = 0; x < field.get_width(); ++x) {
            std::cout << field.get_cell({ x, y }).is_passability() << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T, typename... Args>
void draw_wall(Field& field, T t1, T t2, Args... other) {
    for (unsigned y = t1[1]; y <= t2[1]; ++y) {
        for (unsigned x = t1[0]; x <= t2[0]; ++x) {
            field.get_cell({ x, y }).set_passability(false);
        }
    }
    draw_wall(field, other...);
}

int main() {
    sf::RenderWindow w(sf::VideoMode(1000, 1000), "Game");
    w.setFramerateLimit(60);
    IWindow<sf::RenderWindow>* window = new SFMLWindow(w);
    IMenu* game_menu = new MainMenu(window, new SFMLReader(window), new Game(window, new SFMLReader(window)));
    game_menu->render();
    delete game_menu;

    Field field(15, 15);
    Player player(1, 2);
    Manage manage(player, field);
    for (unsigned y = 0; y < field.get_height(); ++y) {
        for (unsigned x = 0; x < field.get_width(); ++x) {
            if (x < 2 || y < 2 || x > field.get_width() - 3 || y > field.get_height() - 3) {
                field.get_cell({ x, y }).set_passability(false);
            }
        }
    }
    draw_wall(field, Tuple<unsigned>{ 4, 2 }, Tuple<unsigned>{ 4, 3 },
              Tuple<unsigned>{ 6, 2 }, Tuple<unsigned>{ 10, 4 },
              Tuple<unsigned>{ 2, 4 }, Tuple<unsigned>{ 2, 4 },
              Tuple<unsigned>{ 2, 6 }, Tuple<unsigned>{ 5, 8 },
              Tuple<unsigned>{ 6, 8 }, Tuple<unsigned>{ 9, 9 },
              Tuple<unsigned>{ 7, 10 }, Tuple<unsigned>{ 9, 12 },
              Tuple<unsigned>{ 5, 10 }, Tuple<unsigned>{ 6, 10 },
              Tuple<unsigned>{ 2, 10 }, Tuple<unsigned>{ 3, 10 },
              Tuple<unsigned>{ 3, 12 }, Tuple<unsigned>{ 5, 12 },
              Tuple<unsigned>{ 10, 12 }, Tuple<unsigned>{ 10, 12 },
              Tuple<unsigned>{ 10, 11 }, Tuple<unsigned>{ 10, 12 },
              Tuple<unsigned>{ 10, 8 }, Tuple<unsigned>{ 12, 8 },
              Tuple<unsigned>{ 10, 6 }, Tuple<unsigned>{ 12, 6 },
              Tuple<unsigned>{ 10, 7 }, Tuple<unsigned>{ 10, 7 },
              Tuple<unsigned>{ 11, 11 }, Tuple<unsigned>{ 12, 11 }
    );

    field.get_cell({2, 5}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 } }));
    field.get_cell({2, 12}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 } }));
    field.get_cell({6, 12}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 }, { 11, 11 } }));

    FileMahager().write_bin("/home/mikhail/OOP_lab/project/bin/level/level2.bin", field, player, manage);

    return 0;
}
