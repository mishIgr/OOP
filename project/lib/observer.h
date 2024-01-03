//
// Created by mikhail on 07.12.23.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include "Reader/reader.h"

enum Actions {
    Win,
    Lose,
    NewLevel,
    KeyboardPush,
    EnemyMove
};

struct State {

    Actions action;
    Key key;

};

class IObserver {
public:

    virtual void update(State) = 0;

};

#endif //PROJECT_OBSERVER_H
