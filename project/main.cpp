#include <iostream>
#include "lib/lib_game.h"
#include "SFML/Graphics.hpp"

//void draw_wall(Field& field) {
//    for (unsigned y = 0; y < field.get_height(); ++y) {
//        for (unsigned x = 0; x < field.get_width(); ++x) {
//            std::cout << field.get_cell({ x, y }).is_passability() << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//template<typename T, typename... Args>
//void draw_wall(Field& field, T t1, T t2, Args... other) {
//    for (unsigned y = t1[1]; y <= t2[1]; ++y) {
//        for (unsigned x = t1[0]; x <= t2[0]; ++x) {
//            field.get_cell({ x, y }).set_passability(false);
//        }
//    }
//    draw_wall(field, other...);
//}

int main() {
    sf::RenderWindow w(sf::VideoMode(1000, 1000), "Game");
    w.setFramerateLimit(60);

    Player p;
    Field f;
    Manage m(p, f);
    GroupEnemy group_enemy;
//    Enemy enemy1(SchemeMoveWall(f), SchemeAttackPlayer(m), "../sprite/ghost.png");
//    Enemy enemy2(SchemeMove(f, m, {64 + 64, 64}), SchemePushPlayer(p, m), "../sprite/ghost.png");
//    group_enemy.add(enemy1);
//    group_enemy.add(enemy2);
    GameObject game_object(f, p, m, group_enemy);

    SFMLWindow window(w);
    SFMLReader reader(w);
    SFMLChangeKeyMenu change_menu(w, &reader);
    OptionsKeyboardMenu options_keyboard_menu(&window, &reader, &change_menu);
    GamePause game_pause(&window, &reader, &options_keyboard_menu);
    Game game(&window, &reader, &game_pause, game_object);

    DrawGame draw(&game, &window, game_object);
    MessageWin message_win(game_object.player);
    MessageLose message_lose(game_object.manage);
    MessageNewGame message_new_level(game_object);
    MessageKeyboardPush message_keyboard_push;
    StreamCOUT stream_cout(std::cout);
    StreamOutputFile stream_file;
    Logger logger(&game, {/*&stream_cout, &stream_file*/}, {
            { Win, &message_win },
            { Lose, &message_lose },
            { NewLevel, &message_new_level },
            { KeyboardPush, &message_keyboard_push }
    });

    OptionsLoggerMenu options_logger_menu(&window, &reader, &logger, {&stream_cout, &stream_file});

    MainMenu main_menu(&window, &reader, &game, &options_keyboard_menu, &options_logger_menu);

    main_menu.render();

//    Player p;
//    Field f;
//    Manage m(p, f);
//    GroupEnemy g_e;
//    Enemy enemy1(SchemeMoveWall(f), SchemeAttackPlayer(m), "../sprite/ghost.png");
//    GameObject o(f, p, m, g_e);
//    GenerateLevel g(o);
//    g.generate(2);
//    g_e.add(enemy1);
//    FileMahager().write_bin("../bin/level/level2.bin", o);

//    Field field(15, 15);
//    Player player(1, 2);
//    Manage manage(player, field);
//    for (unsigned y = 0; y < field.get_height(); ++y) {
//        for (unsigned x = 0; x < field.get_width(); ++x) {
//            if (x < 2 || y < 2 || x > field.get_width() - 3 || y > field.get_height() - 3) {
//                field.get_cell({ x, y }).set_passability(false);
//            }
//        }
//    }
//    draw_wall(field, Tuple<unsigned>{ 4, 2 }, Tuple<unsigned>{ 4, 3 },
//              Tuple<unsigned>{ 6, 2 }, Tuple<unsigned>{ 10, 4 },
//              Tuple<unsigned>{ 2, 4 }, Tuple<unsigned>{ 2, 4 },
//              Tuple<unsigned>{ 2, 6 }, Tuple<unsigned>{ 5, 8 },
//              Tuple<unsigned>{ 6, 8 }, Tuple<unsigned>{ 9, 9 },
//              Tuple<unsigned>{ 7, 10 }, Tuple<unsigned>{ 9, 12 },
//              Tuple<unsigned>{ 5, 10 }, Tuple<unsigned>{ 6, 10 },
//              Tuple<unsigned>{ 2, 10 }, Tuple<unsigned>{ 3, 10 },
//              Tuple<unsigned>{ 3, 12 }, Tuple<unsigned>{ 5, 12 },
//              Tuple<unsigned>{ 10, 12 }, Tuple<unsigned>{ 10, 12 },
//              Tuple<unsigned>{ 10, 11 }, Tuple<unsigned>{ 10, 12 },
//              Tuple<unsigned>{ 10, 8 }, Tuple<unsigned>{ 12, 8 },
//              Tuple<unsigned>{ 10, 6 }, Tuple<unsigned>{ 12, 6 },
//              Tuple<unsigned>{ 10, 7 }, Tuple<unsigned>{ 10, 7 },
//              Tuple<unsigned>{ 11, 11 }, Tuple<unsigned>{ 12, 11 }
//    );
//
//    field.get_cell({2, 5}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 } }));
//    field.get_cell({2, 12}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 } }));
//    field.get_cell({6, 12}).set_event(new EventChangeField(field, { { 3, 6 }, { 3, 7 }, { 3, 8 }, { 11, 11 } }));
//
//    FileMahager().write_bin("/home/mikhail/OOP_lab/project/bin/level/level2.bin", field, player, manage);

    return 0;
}
