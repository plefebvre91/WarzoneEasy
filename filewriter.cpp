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

    fp.seekg(54, fp.beg);

    char bytes[2];

    fp.read(bytes, 2);
    for(int i=0;i<2;i++)
    {
        power |= bytes[i];
        power <<= (8 - 8*i);
    }


    fp.close();
//
    return power;
}

int FileWriter::setPower(unsigned short p){
    std::ofstream fp(filename.c_str(), std::ios::out|std::ios::in|std::ios::binary);
    if(!fp) {
        return FW_ERROR;
    }

    fp.seekp(54, fp.beg);

    char bytes[2];


    bytes[1] = ((p) & 0x00FF);
    bytes[0] = ((p >> 8) & 0x00FF);

    fp.write(bytes, 2);
    fp.close();

    return 0;
}
