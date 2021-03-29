#ifndef DETECT_LANGUAGE 
#define DETECT_LANGUAGE
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <ctype.h>
#include <vector>
#include <string>
#include "utils.hpp"

enum languages{ENGLISH, GERMAN, FRENCH, SPANISH};
#define GAME_LOGO "data/detect-language.logo"
#define INPUT_FREQUENCIES_DATA "data/letter_frequency.csv"


struct languagesScore 
{
    languagesScore(std::wstring &gname, double gscore)
    {
        this->name = gname;
        this->score = gscore;
    }
    std::wstring name;
    double score;
};

struct gameResult {
    gameResult() {
        bestIndex = -1;
    }
    std::vector<languagesScore> languages;
    int bestIndex;
    gameResult handle_input (std::wstring input, dictionaryParameters dict);
    void print();
};


#endif