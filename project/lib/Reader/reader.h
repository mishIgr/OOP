//
// Created by mikhail on 19.11.23.
//

#ifndef PROJECT_READER_H
#define PROJECT_READER_H

#include <vector>
#include <string>

enum Commands {
    Close,
    Enter,
    Back,
    Restart,
    Up,
    Down,
    Left,
    Right,
    DUp,
    DDown,
    DLeft,
    DRight,
    None
};

struct Key {

    Commands com;
    std::string keyboard;

};

class InReader {
public:

    virtual std::vector<Key> get_commands(bool = false) = 0;
    virtual std::vector<std::string> get_key_str() = 0;
    virtual void reset_config() = 0;
    virtual void update() = 0;
    virtual ~InReader() {}

};

#endif //PROJECT_READER_H
