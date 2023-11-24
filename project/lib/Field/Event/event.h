#ifndef event_h
#define event_h

#include <string>

class IEvent {
public:

    virtual void event() = 0;
    virtual std::string get_str() = 0;
    virtual ~IEvent() {}
    virtual IEvent* copy() = 0;

};

#endif