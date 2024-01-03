#ifndef game_h
#define game_h

#include "Menu/menu.h"
#include "Reader/reader.h"
#include "window.h"
#include "observable.h"
#include "Object/game_object.h"

class Game : public IObservable {

    IWindow* window;
    InReader* reader;
    IMenu* game_pause;
    GameObject& game_object;
    std::vector<IObserver*> observers;

public:

    Game(IWindow*, InReader*, IMenu*, GameObject&);

    void add(IObserver*);
    void del(IObserver*);
    void notify(State);
    void render();

};

#endif