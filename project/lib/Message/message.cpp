//
// Created by mikhail on 11.12.23.
//

#include "message.h"

std::ostream &operator<<(std::ostream& out, Message* message) {
    out<<message->get_message();
    return out;
}
