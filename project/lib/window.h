//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

#include "Reader/reader.h"

struct Vector2U {
    unsigned x;
    unsigned y;
};

class IWindow {
public:

    virtual bool is_open() = 0;
    virtual void close() = 0;
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual Vector2U get_size() = 0;
    virtual std::vector<Key> poll_event() = 0;
    virtual void draw_texts(std::vector<std::string>, std::string, unsigned, unsigned) = 0;
    virtual void draw_texts(std::vector<std::string>, std::string, unsigned, unsigned, std::pair<std::pair<float, float>, std::pair<float, float>>) = 0;
    virtual void draw_sprite(std::string, std::pair<float, float>) = 0;
    virtual ~IWindow() {}

};

#endif //PROJECT_WINDOW_H
