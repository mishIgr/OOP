#include <iostream>
#include "lib/game.h"

int main() {
    Player p;
    Field f;
    Manage m(p, f);
    m.move(LEFT);
    return 0;
}
