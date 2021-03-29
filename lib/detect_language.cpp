#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
// #include <ctype.h>
#include <vector>
#include <string>
#include <limits>


#include "alpha_stat.hpp"
#include "utils.hpp"
#include "detect_language.hpp"


void gameResult::print() {
    for (size_t i = 0; i < languages.size(); i++) {
        std::wcout << languages[i].name << " : " << languages[i].score << "\n";
    }
    std::wcout << languages[bestIndex].name << " has best Score with " << languages[bestIndex].score << "\n";
}

gameResult gameResult::handle_input (std::wstring input, dictionaryParameters dict) 
{
    std::getline(std::wcin, input);
    alphabetStatistics stats = alphabetStat(dict.allLetters, input);
    std::wstring proposedLanguage = L"";
    double bestScore = std::numeric_limits<double>::max();
    gameResult res;
    for (size_t i = 0; i < dict.width; i++) {
        languagesScore score(dict.languages[i].name, 0.0);
        score.score = 0.0;
        for (size_t j = 0; j < dict.allLetters.size(); j++) {
                
            if (stats.frequency[j] > 0.)
            {              
                double error = dict.languages[i].frequencies[j] - stats.frequency[j];
                error *= error;
                score.score += error;
            }
            else 
                score.score +=  dict.languages[i].frequencies[j] *  dict.languages[i].frequencies[j] + 0.01;
            
        }
        res.languages.push_back(score);
        if (score.score < bestScore) {
            bestScore = score.score;
            res.bestIndex = i;
            proposedLanguage = dict.languages[i].name;
        }
    }
    return res;
}