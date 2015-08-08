#include "filewriter.h"

FileWriter::FileWriter(const char* str): power(0), filename(str) {}
FileWriter::~FileWriter(){}

int FileWriter::getPower()
{
    // Open the game file
    std::ifstream fp(filename.c_str(),std::ios::in);

    // Return if it's failed
    if(fp.fail())
    {
        return FW_ERROR;
    }

    // Place cursor at right offset
    fp.seekg(FW_POWER_OFFSET, fp.beg);

    // Buffer
    char bytes[FW_POWER_DATA_SIZE];

    // Read current value
    fp.read(bytes, FW_POWER_DATA_SIZE);

    // Close file
    fp.close();

    // Convert into unsigned int
    for(int i=0;i<FW_POWER_DATA_SIZE;i++)
    {
        power |= bytes[i];
        power <<= (FW_BYTE_SIZE - FW_BYTE_SIZE*i);
    }

    return power;
}

int FileWriter::setPower(int p){
    // Open game file
    std::ofstream fp(filename.c_str(), std::ios::out|std::ios::in|std::ios::binary);

    // Return if it's failed
    if(fp.fail())
    {
        return FW_ERROR;
    }

    // Place cursor at right offset
    fp.seekp(FW_POWER_OFFSET , fp.beg);

    // Buffer
    char bytes[FW_POWER_DATA_SIZE];

    // Convert unsigned int power into byte array
    bytes[1] = (p & 0xFF);
    bytes[0] = ((p >> FW_BYTE_SIZE) & 0xFF);

    // Write into the game file
    fp.write(bytes, FW_POWER_DATA_SIZE);

    // Close file
    fp.close();

    return power;
}
