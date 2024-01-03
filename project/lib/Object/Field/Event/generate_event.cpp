#ifndef generate_event_cpp
#define generate_event_cpp

#include "generate_event.h"
#include <typeinfo>
#include <map>

IEvent* GenerateEvent::generate_event_change_field(std::string& content) {
    size_t size = *reinterpret_cast<const size_t*>(content.substr(0, sizeof(size_t)).c_str());
    content = content.substr(sizeof(size_t));
    Tuple<unsigned>* arg = new Tuple<unsigned>[size];

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            arg[i][j] = *reinterpret_cast<const unsigned*>(content.substr(0, sizeof(unsigned)).c_str());
            content = content.substr(sizeof(unsigned));
        }
    }

    EventChangeField* tmp = new EventChangeField(field, arg, size);
    delete [] arg;
    return tmp;
}

IEvent* GenerateEvent::generate_event_change_xp(std::string& content) {
    unsigned xp_change = *reinterpret_cast<const unsigned*>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    return new EventChangeXP(this->player, xp_change);
}

IEvent* GenerateEvent::generate_event_jump(std::string& content) {
    unsigned xp_change = *reinterpret_cast<const unsigned*>(content.substr(0, sizeof(unsigned)).c_str());
    content = content.substr(sizeof(unsigned));
    return new EventChangeXP(this->player, xp_change);
}

IEvent* GenerateEvent::generate_null_event(std::string&) { return nullptr; }

GenerateEvent::GenerateEvent(Field& field, Player& player) : field(field), player(player) {}

IEvent* GenerateEvent::generate_event(std::string& content) {
    size_t hash_code = *reinterpret_cast<const size_t*>(content.substr(0, sizeof(size_t)).c_str());
    content = content.substr(sizeof(size_t));

    std::map<size_t, IEvent*(GenerateEvent::*)(std::string&)> function {
        {0, &GenerateEvent::generate_null_event},
        {typeid(EventChangeField).hash_code(), &GenerateEvent::generate_event_change_field},
        {typeid(EventChangeXP).hash_code(), &GenerateEvent::generate_event_change_xp},
        {typeid(EventJump).hash_code(), &GenerateEvent::generate_event_jump}
    };

    return (this->*function[hash_code])(content);
}

#endif