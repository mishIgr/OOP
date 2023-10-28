#include <iostream>
#include "lib/game.h"

int main() {
    Player p;
    IEvent* e = new EventChangeXP(p, 1);
    std::cout << typeid(*e).name() << std::endl;
    return 0;
}
