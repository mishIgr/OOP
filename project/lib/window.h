//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

#include "SFML/Graphics.hpp"

template<typename Window>
concept WindowConcept = requires(Window window) {
    {window.isOpen()};
    {window.close()};
    {window.clear()};
    {window.display()};
    {window.getSize()};
    {window.getSize().x};
    {window.getSize().y};
};

template<WindowConcept Window>
class IWindow {
public:

    virtual Window& get_window() = 0;

};

#endif //PROJECT_WINDOW_H
