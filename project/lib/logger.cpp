//
// Created by mikhail on 10.12.23.
//

#include "logger.h"
#include "Message/message_keyboard_push.h"

Logger::Logger(IObservable* observable, std::vector<Stream*> streams, std::map<Actions, Message*> com_messages)
: streams(std::move(streams)), com_messages(std::move(com_messages)) { observable->add(this); }

void Logger::set_streams(std::vector<Stream*> new_streams) { this->streams = std::move(new_streams); }

std::vector<Stream*> Logger::get_streams() { return this->streams; }

void Logger::update(State state) {
    if (state.action == KeyboardPush) {
        this->com_messages[state.action]->update(state.key);
        for (auto s : this->streams)
            *s << this->com_messages[state.action];
        return;
    }

    auto it = this->com_messages.find(state.action);
    if (it == this->com_messages.end()) {
        for (auto s : this->streams)
            *s << "!!! Action in logger not found\n";
        return;
    }

    for (auto s : this->streams)
        *s << it->second;
}
