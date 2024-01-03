//
// Created by mikhail on 25.12.23.
//

#ifndef PROJECT_SCHEME_PUSH_PLAYER_H
#define PROJECT_SCHEME_PUSH_PLAYER_H

#include "Object/Player/manage.h"

class SchemePushPlayer {

    Player& player;
    Manage& manage;

public:

    SchemePushPlayer(Player&, Manage&);

    bool interaction();
    size_t get_id();

};

#endif //PROJECT_SCHEME_PUSH_PLAYER_H
