//
// Created by mikhail on 22.12.23.
//

#ifndef PROJECT_SCHEME_ATTACK_PLAYER_H
#define PROJECT_SCHEME_ATTACK_PLAYER_H

#include "Object/Player/manage.h"

class SchemeAttackPlayer {

    Manage& manage;

public:

    SchemeAttackPlayer(Manage&);

    bool interaction();
    size_t get_id();

};

#endif //PROJECT_SCHEME_ATTACK_PLAYER_H
