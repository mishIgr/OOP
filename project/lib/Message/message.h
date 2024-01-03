//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H

#include <string>
#include "Reader/reader.h"
#include <iostream>

class Message {
public:

    virtual std::string get_message() = 0;

    virtual void update(Key) {}

    friend std::ostream &operator<<(std::ostream &out, Message *message);

};

#endif //PROJECT_MESSAGE_H
