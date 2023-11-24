cmake_minimum_required(VERSION 3.26)
project(project)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(project
        lib/Field/cell.cpp
        lib/Field/cell.h
        lib/Field/Event/event.h
        lib/Field/Event/event_change_field.cpp
        lib/Field/Event/event_change_field.h
        lib/Field/Event/event_change_xp.cpp
        lib/Field/Event/event_change_xp.h
        lib/Field/Event/event_jump.cpp
        lib/Field/Event/event_jump.h
        lib/Field/field.cpp
        lib/Field/field.h
        lib/File_manager/file_manager.cpp
        lib/File_manager/file_manager.h
        lib/game.h
        lib/Field/Event/generate_event.cpp
        lib/Field/Event/generate_event.h
        lib/keyboard.cpp
        lib/keyboard.h
        lib/lib_game.h
        lib/Player/manage.cpp
        lib/Player/manage.h
        lib/Player/player.cpp
        lib/Player/player.h
        lib/tuple.h
        main.cpp
        lib/reader.h
        lib/sfml_reader.h
        lib/menu.h
        lib/main_menu.h
        lib/draw_text.h
        lib/window.h
        lib/sfml_window.h
        lib/sfml_window.cpp
        lib/options_menu.h
        lib/sfml_config_scheme.h
        lib/sfml_config_scheme.cpp
        lib/sfml_change_key_menu.h
        lib/field_render.h
        lib/sfml_field_render.h
)

target_link_libraries(project sfml-graphics sfml-audio)