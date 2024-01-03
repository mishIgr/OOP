//
// Created by mikhail on 07.12.23.
//

#ifndef PROJECT_GAME_OBJECT_H
#define PROJECT_GAME_OBJECT_H

#include "Field/field.h"
#include "Player/player.h"
#include "Player/manage.h"
#include "GroupEnemy/group_enemy.h"

struct GameObject {

    Field& field;
    Player& player;
    Manage& manage;
    GroupEnemy& group_enemy;

};

#endif //PROJECT_GAME_OBJECT_H
