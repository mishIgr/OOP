#include <iostream>
#include "lib/game.h"

int main() {
    Tuple<int> a(2);
    a[0] = 1;
    a[1] = 1;
    Tuple<int> b(2);
    b[0] = 2;
    b[1] = 3;
    a = b + a;
    std::cout << a[0] << a[1] << std::endl;
    return 0;
}
