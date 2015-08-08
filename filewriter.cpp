/*
    Warzone file game updater
    Copyright (C) 2015  Pierre Lefebvre

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
    power |= bytes[0];
    power <<= FW_BYTE_SIZE;
    power |= bytes[1];

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
