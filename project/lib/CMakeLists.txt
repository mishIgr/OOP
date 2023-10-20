cmake_minimum_required(VERSION 3.25)
project(Lib)
add_library(
    game_lib
    tuple.cpp field.cpp cell.cpp manage.cpp player.cpp
    tuple.h field.h cell.h manage.h player.h event.h game.h
)
target_include_directories(
    game_lib PUBLIC
    {CMAKE_CURRENT_SOURCE_DIR}
)
