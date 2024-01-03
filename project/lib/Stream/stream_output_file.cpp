//
// Created by mikhail on 10.12.23.
//

#include "stream_output_file.h"
#include "iostream"

StreamOutputFile::StreamOutputFile(std::string file_name) {
    file_name = "/home/mikhail/OOP_lab/project/log/" + file_name;
    std::cout << file_name << std::endl;
    this->out.open(file_name);
}

StreamOutputFile::~StreamOutputFile() { this->out.close(); }

Stream* StreamOutputFile::operator << (std::string s) {
    this->out << s;
    return this;
}

Stream* StreamOutputFile::operator << (Message* message) {
    this->out << message;
    return this;
}