//
// Created by mikhail on 27.11.23.
//

#ifndef PROJECT_CHANGE_KEY_MENU_H
#define PROJECT_CHANGE_KEY_MENU_H

#include "Reader/reader.h"

class IChangeMenu {
public:

    virtual void reset(Commands) = 0;
    virtual ~IChangeMenu() {}

};

#endif //PROJECT_CHANGE_KEY_MENU_H
