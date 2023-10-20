#ifndef manage_h
#define manage_h

#include "player.h"
#include "field.h"


enum Direct {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    D_UP,
    D_LEFT,
    D_DOWN,
    D_RIGHT
};

class Manage {

    Player& player;
    Field& field;
    int x;
    int y;

public:

    Manage(Player&, Field&);
    Manage(Player&, Field&, unsigned, unsigned);

    bool move(Direct);

    void damage(unsigned);
    void heal(unsigned);
};

#endif