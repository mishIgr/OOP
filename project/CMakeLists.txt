cmake_minimum_required(VERSION 3.26)
project(project)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(project
        lib/Object/Field/cell.cpp
        lib/Object/Field/cell.h
        lib/Object/Field/Event/event.h
        lib/Object/Field/Event/event_change_field.cpp
        lib/Object/Field/Event/event_change_field.h
        lib/Object/Field/Event/event_change_xp.cpp
        lib/Object/Field/Event/event_change_xp.h
        lib/Object/Field/Event/event_jump.cpp
        lib/Object/Field/Event/event_jump.h
        lib/Object/Field/field.cpp
        lib/Object/Field/field.h
        lib/File_manager/file_manager.cpp
        lib/File_manager/file_manager.h
        lib/game.h
        lib/Object/Field/Event/generate_event.cpp
        lib/Object/Field/Event/generate_event.h
        lib/Reader/keyboard.cpp
        lib/Reader/keyboard.h
        lib/lib_game.h
        lib/Object/Player/manage.cpp
        lib/Object/Player/manage.h
        lib/Object/Player/player.cpp
        lib/Object/Player/player.h
        lib/tuple.h
        main.cpp
        lib/Reader/reader.h
        lib/Reader/sfml_reader.h
        lib/Menu/menu.h
        lib/Menu/main_menu.h
        lib/window.h
        lib/sfml_window.h
        lib/sfml_window.cpp
        lib/Menu/options_keyboard_menu.h
        lib/Reader/sfml_config_scheme.h
        lib/Reader/sfml_config_scheme.cpp
        lib/Menu/sfml_change_key_menu.h
        lib/Reader/sfml_reader.cpp
        lib/Menu/options_keyboard_menu.cpp
        lib/Menu/main_menu.cpp
        lib/Menu/sfml_change_key_menu.cpp
        lib/Menu/change_key_menu.h
        lib/game.cpp
        lib/generate_level.h
        lib/generate_level.cpp
        lib/game_pause.h
        lib/game_pause.cpp
        lib/observable.h
        lib/observer.h
        lib/draw_game.h
        lib/draw_game.cpp
        lib/Object/game_object.h
        lib/Message/message.h
        lib/logger.h
        lib/logger.cpp
        lib/Message/message_win.h
        lib/Message/message_win.cpp
        lib/Message/message_lose.h
        lib/Message/message_lose.cpp
        lib/Message/message_new_game.h
        lib/Message/message_new_game.cpp
        lib/Message/message_keyboard_push.h
        lib/Message/message_keyboard_push.cpp
        lib/Stream/stream.h
        lib/Stream/stream_cout.h
        lib/Stream/stream_cout.cpp
        lib/Stream/stream_output_file.h
        lib/Stream/stream_output_file.cpp
        lib/Menu/options_logger_menu.h
        lib/Menu/options_logger_menu.cpp
        lib/Message/message.cpp
        lib/sprites.h
        lib/Object/GroupEnemy/Enemy/enemy.h
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_move_wall.h
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_move_wall.cpp
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_attack_player.h
        lib/Object/GroupEnemy/group_enemy.h
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_attack_player.cpp
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_move.h
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_move.cpp
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_push_player.h
        lib/Object/GroupEnemy/Enemy/Scheme/scheme_push_player.cpp
)

target_link_libraries(project sfml-graphics sfml-audio)