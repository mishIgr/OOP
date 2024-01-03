//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_STREAM_H
#define PROJECT_STREAM_H

#include "Message/message.h"

class Stream {
public:

    virtual Stream* operator << (Message*) = 0;
    virtual Stream* operator << (std::string) = 0;
    virtual ~Stream() {};

};

#endif //PROJECT_STREAM_H
