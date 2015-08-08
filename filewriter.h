#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>


#define FW_ERROR -1;

class FileWriter
{
public:
    FileWriter(const char*str);
    ~FileWriter();

    int getPower();
    int setPower(unsigned int power);

private:
    unsigned int power;
    std::string filename;
};

#endif // FILEWRITER_H
