#ifndef ALPHA_STATS 
#define ALPHA_STATS

#include <iostream>
#include <ctype.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALPHABET_LANGUAGE_COUNT 26
#define MAX_STR 1024 * 1024


struct alphabetStatistics 
{
    alphabetStatistics() {
        this->count = 0;
        this->alphabet = NULL;
        this->frequency = NULL;
    }
    ~alphabetStatistics() {
 
    }
    void setAlphabet(std::wstring occurences, int size)
    {
        this->alphabet = new size_t[size]();
        this->frequency = new double[size]();
        this->occurencies = occurences;
    }
// private:
    size_t *alphabet;
    size_t count;
    std::wstring occurencies;
    double *frequency;
    alphabetStatistics alphabetStat(std::wstring str);
};

std::wstring allLanguagesOccurence(std::vector<std::wstring> languages);
int levenshtein(std::wstring seq1, std::wstring seq2);
alphabetStatistics alphabetStat(std::wstring occurences, std::wstring str);
double *calculateFreq(alphabetStatistics stats);
void printFrequencies(alphabetStatistics stats);
std::wstring orderedString(alphabetStatistics stats);

#endif
