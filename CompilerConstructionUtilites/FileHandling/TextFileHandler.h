#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class TextFileHandler
{
private:
    std::string fileName;
    std::fstream file;
public:
    TextFileHandler(std::string, bool);
    std::vector<std::string> getLines();
    std::string getText();
    ~TextFileHandler();
};

/**
 * @brief Construct a new Text File Handler:: Text File Handler object
 * 
 * @param fileName 
 * @param createIfNotExist 
 */
TextFileHandler::TextFileHandler(std::string fileName, bool createIfNotExist = false)
{

    this->fileName = fileName;
    this->file = std::fstream(fileName);

    if (createIfNotExist && !file.is_open()) {
        file.open(fileName);
    }

}

/**
 * @brief returns the file line by line
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> TextFileHandler::getLines() {
    std::vector<std::string> res;
    std::string curr = "";

    while (getline(file, curr)) {
        res.push_back(curr);
    }

    return res;
}

/**
 * @brief return the file as a string
 * 
 * @return std::string 
 */
std::string TextFileHandler::getText() {
    std::string res = "", curr = "";

    while (getline(file, curr)) res += curr;

    return res;
}

/**
 * @brief Destroy the Text File Handler:: Text File Handler object
 * 
 */
TextFileHandler::~TextFileHandler()
{
    file.close();
}