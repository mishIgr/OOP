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
    DRight
};

class InReader {
public:

    virtual std::vector<Commands> get_commands() = 0;
    virtual std::vector<std::string> get_key_str() = 0;
    virtual void reset_config() = 0;
    virtual ~InReader() {}

};

#endif //PROJECT_READER_H
