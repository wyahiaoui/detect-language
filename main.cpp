#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <string>


#include "alpha_stat.hpp"
#include "utils.hpp"
#include "detect_language.hpp"

#define ENCONDING_UTF8 "en_US.UTF-8"

/*
* Detect language using statistics,
* The program read the file loacted in data and use the given frequencies,
* This file has to have the csv separted by a comma ','
*
* @input string 
*       - This input can be given through the console 
*  It calculates the letter frequency inside the given string 
* and retrieve the error between this valeur and the expected value from the csv file
* 
*/

using namespace std;


int main(int argc, char **argv)
{
    std::setlocale(LC_ALL, ENCONDING_UTF8);
    if (argc > 1) {
        std::setlocale(LC_ALL, argv[1]);
    }
    dictionaryParameters dict = readDictionary(INPUT_FREQUENCIES_DATA);
    std::string ss = GAME_LOGO;
    std::wstring logo = readFile(ss.c_str());
    std::wcout << logo << "\n";
    std::string str;
    std::wstring input;
    while (1) {
        std::wcout  << "Please enter a language:\n";
        std::wcin >> input;
        gameResult res;
        if (input.size() > 0)
            res = res.handle_input(input, dict);
        res.print();
    }
}