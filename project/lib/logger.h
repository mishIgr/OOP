//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_LOGGER_H
#define PROJECT_LOGGER_H

#include "Message/message.h"
#include "Stream/stream.h"
#include "observable.h"
#include <map>

class Logger : public IObserver{

    std::vector<Stream*> streams;
    std::map<Actions, Message*> com_messages;

public:

    Logger(IObservable*, std::vector<Stream*>, std::map<Actions, Message*>);

    void set_streams(std::vector<Stream*>);
    std::vector<Stream*> get_streams();

    void update(State);

};

#endif //PROJECT_LOGGER_H
