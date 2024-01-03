//
// Created by mikhail on 10.12.23.
//

#ifndef PROJECT_STREAM_OUTPUT_FILE_H
#define PROJECT_STREAM_OUTPUT_FILE_H

#include "stream.h"
#include "fstream"

class StreamOutputFile : public Stream {

    std::ofstream out;

public:

    StreamOutputFile(std::string = "ouput.txt");
    ~StreamOutputFile();

    Stream* operator << (std::string);
    Stream* operator << (Message*);

};
#endif //PROJECT_STREAM_OUTPUT_FILE_H
