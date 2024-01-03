//
// Created by mikhail on 10.12.23.
//

#include "stream_cout.h"

StreamCOUT::StreamCOUT(std::ostream& out) : out(out) {}

Stream* StreamCOUT::operator << (std::string s) {
    this->out << s;
    return this;
}

Stream* StreamCOUT::operator << (Message* message) {
    this->out << message;
    return this;
}