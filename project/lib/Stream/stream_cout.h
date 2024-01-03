//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_STREAM_COUT_H
#define PROJECT_STREAM_COUT_H

#include "stream.h"

class StreamCOUT : public Stream {

    std::ostream& out;

public:

    StreamCOUT(std::ostream&);

    Stream* operator << (std::string);
    Stream* operator << (Message*);

};

#endif //PROJECT_STREAM_COUT_H
