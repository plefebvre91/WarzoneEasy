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
#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>

#define FW_ERROR -1
#define FW_BYTE_SIZE 8
#define FW_POWER_OFFSET 54
#define FW_POWER_DATA_SIZE 2

/**
 * @brief The FileWriter class
 */
class FileWriter
{
public:
    /**
     * @brief Constructor
     * @param str .game file to load
     */
    FileWriter(const char*str);

    /**
      * @brief Destructor
      */
    ~FileWriter();

    /**
     * @brief getPower
     * @return the power resource read from file, or FW_ERROR
     */
    int getPower();

    /**
     * @brief setPower
     * @param p the new power to write
     * @return the power resource written in file, or FW_ERROR
     */
    int setPower(int p);

private:
    int power;
    std::string filename;
};

#endif // FILEWRITER_H
