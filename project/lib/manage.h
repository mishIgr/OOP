#ifndef manage_h
#define manage_h

#include "player.h"
#include "field.h"
#include "tuple.h"

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
    const Field& field;
    Tuple<unsigned> coord;


public:

    Manage(Player&, Field&);
    Manage(Player&, Field&, unsigned, unsigned);
    Manage(Player&, Field&, Tuple<unsigned>);

    bool move(Direct);

    void damage(unsigned);
    void heal(unsigned);
};

#endif