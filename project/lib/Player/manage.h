#ifndef manage_h
#define manage_h

#include "Player/player.h"
#include "Field/field.h"
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
    Field& field;
    Tuple<unsigned> coord;


public:

    Manage(Player&, Field&);
    Manage(Player&, Field&, Tuple<unsigned>);
    Manage(Player&, Field&, unsigned, unsigned);
    Manage(const Manage&);
    Manage(Manage&&);

    Manage& operator=(const Manage&);
    Manage& operator=(Manage&&);

    bool move(Direct);

    void damage(unsigned);
    void heal(unsigned);

    Tuple<unsigned> get_coord();
};

#endif