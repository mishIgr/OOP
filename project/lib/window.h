//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

#include "SFML/Graphics.hpp"

template<typename Window>
class IWindow {
public:

    virtual Window& get_window() = 0;

};

#endif //PROJECT_WINDOW_H
