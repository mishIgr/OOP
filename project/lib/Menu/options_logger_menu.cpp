//
// Created by mikhail on 11.12.23.
//

#include "options_logger_menu.h"
#include "Stream/stream_output_file.h"
#include "Stream/stream_cout.h"

OptionsLoggerMenu::OptionsLoggerMenu(IWindow* window, InReader* reader, Logger* logger, std::vector<Stream*> possible_streams) :
window(window), reader(reader), logger(logger), possible_streams(std::move(possible_streams)), pointer(0) {}

void OptionsLoggerMenu::render() {
    if (this->reader == nullptr || this->window == nullptr || this->logger == nullptr)
        return;

    while (this->window->is_open()) {
        std::string info;
        std::vector<std::string> menu_items {
            "Logger off",
            "Logger console",
            "Logger file",
            "Logger console and file"
        };

        for (auto key: this->reader->get_commands()) {
            if (key.com == Close)
                this->window->close();
            else if (key.com == Back)
                return;
            else if (key.com == Up)
                this->pointer = (this->pointer + menu_items.size() - 1) % menu_items.size();
            else if (key.com == Down)
                this->pointer = (this->pointer + 1) % menu_items.size();
            else if (key.com == Enter) {
                if (this->pointer == 0)
                    logger->set_streams({});
                else if (this->pointer == 1) {
                    std::vector<Stream*> new_streams;
                    for (auto p : this->possible_streams)
                        if (dynamic_cast<StreamCOUT*>(p))
                            new_streams.push_back(p);
                    this->logger->set_streams(new_streams);
                }
                else if (this->pointer == 2) {
                    std::vector<Stream*> new_streams;
                    for (auto p : this->possible_streams)
                        if (dynamic_cast<StreamOutputFile*>(p))
                            new_streams.push_back(p);
                    this->logger->set_streams(new_streams);
                }
                else {
                    std::vector<Stream*> new_streams;
                    for (auto p : this->possible_streams) {
                        if (dynamic_cast<StreamCOUT *>(p))
                            new_streams.push_back(p);
                        if (dynamic_cast<StreamOutputFile *>(p))
                            new_streams.push_back(p);
                    }
                    this->logger->set_streams(new_streams);
                }
            }
        }

        info = "Now logger:";
        auto streams = logger->get_streams();
        bool flag_off = true;

        for (auto p : streams) {
            if (dynamic_cast<StreamCOUT*>(p)) {
                if (!flag_off)
                    info += ',';
                info += " console";
                flag_off = false;
            }
            if (dynamic_cast<StreamOutputFile*>(p)) {
                if (!flag_off)
                    info += ',';
                info += " file";
                flag_off = false;
            }
        }
        if (flag_off)
            info += " off";

        this->window->clear();

        this->window->draw_texts(menu_items,
                                 "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, this->pointer,
                                 {{0, 30}, {this->window->get_size().x, this->window->get_size().y}}
                                 );

        this->window->draw_texts({info},
                                 "/home/mikhail/OOP_lab/project/font/Nunito/Nunito-VariableFont_wght.ttf", 25, -1,
                                 {{0, 0}, {this->window->get_size().x, this->window->get_size().y - 30 * menu_items.size()}}
        );

        this->window->display();
    }
}