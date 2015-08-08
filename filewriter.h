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
