//
// Created by mikhail on 07.12.23.
//

#ifndef PROJECT_OBSERVABLE_H
#define PROJECT_OBSERVABLE_H

#include "Reader/reader.h"
#include "observer.h"

class IObservable {
public:

    virtual void add(IObserver*) = 0;
    virtual void del(IObserver*) = 0;
    virtual void notify(State) = 0;

};

#endif //PROJECT_OBSERVABLE_H
