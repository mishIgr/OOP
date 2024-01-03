//
// Created by mikhail on 27.11.23.
//

#ifndef PROJECT_GENERATE_LEVEL_H
#define PROJECT_GENERATE_LEVEL_H

#include "Object/game_object.h"
#include "File_manager/file_manager.h"

class GenerateLevel {

    unsigned order_level;
    GameObject& game_object;
    std::string file_fun(unsigned);

public:

    GenerateLevel(GameObject&);

    bool generate(unsigned);
    bool restart();
    bool next_level();

};

#endif //PROJECT_GENERATE_LEVEL_H
