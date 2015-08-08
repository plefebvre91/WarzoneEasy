#include "filewriter.h"

FileWriter::FileWriter(const char* str):
    power(0),
    filename(str)
     {}

FileWriter::~FileWriter(){

}

int FileWriter::getPower()
{
    std::ifstream fp(filename.c_str(),std::ios::in);
    if(!fp) {
        return FW_ERROR;
    }

    fp.seekg(52, fp.beg);

    char bytes[4];

    fp.read(bytes, 4);
    for(int i=0;i<4;i++)
    {
        power |= bytes[i];
        power <<= (24 - 8*i);
    }


    fp.close();
//
    return power;
}

int FileWriter::setPower(unsigned int power){
    std::ofstream fp(filename.c_str(),std::ios::binary);
    if(!fp) {
        return FW_ERROR;
    }

    fp.seekp(52, fp.beg);

    char bytes[4];


    bytes[3] = (power & 0xFF);
    bytes[2] =  ((power >> 8) & 0xFF);
    bytes[1] =   ((power >> 16) & 0xFF);
    bytes[0] =  ((power >> 24) & 0xFF);

    fp.write(bytes, 4);
    fp.close();

    return 0;
}
