#ifndef event_h
#define event_h

class IEvent {
public:

    virtual void event() = 0;
    virtual IEvent* copy() = 0;

};

#endif