//
// Created by mikhail on 07.12.23.
//

#ifndef PROJECT_DRAW_GAME_H
#define PROJECT_DRAW_GAME_H

#include "observer.h"
#include "window.h"
#include "observable.h"
#include "Object/game_object.h"

class DrawGame : public IObserver {

    IWindow* window;
    GameObject& game_object;

public:

    DrawGame(IObservable*, IWindow*, GameObject&);
    void update(State);

};

#endif //PROJECT_DRAW_GAME_H
