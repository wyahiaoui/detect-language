#include <iostream>

#include "alpha_stat.hpp"



std::wstring allLanguagesOccurence(std::vector<std::wstring> languages) {
    std::wstring occurences = languages[0];
    std::vector<std::wstring>::iterator it;
    for(it = languages.begin(); it != languages.end(); ++it) {
        std::wstring tmp = it->c_str();
        for (wchar_t &c : tmp) {
            if (occurences.find(c) == std::string::npos) {
                occurences += c;
            }
        }
    }
    return occurences;
}


double *calculateFreq(alphabetStatistics stats)
{
    size_t len = stats.occurencies.length();
    double *freq = new double[len];
    for (size_t i = 0; i < len; i++) {
        freq[i] = (double)stats.alphabet[i]/stats.count;
    }
    return freq;
}

void printFrequencies(alphabetStatistics stats) 
{
    for (size_t i = 0; i < stats.occurencies.length(); i++) {
        std::wcout << stats.occurencies[i] << ": " << stats.frequency[i] << " ";
    } 
    std::wcout << std::endl;
}

alphabetStatistics alphabetStat(std::wstring occurences, std::wstring str)
{
    alphabetStatistics freq; 
    size_t occurencesLen = occurences.length();
    freq.setAlphabet(occurences, occurencesLen);
    for (wchar_t &c : str ) {
        if (iswalpha(c)) {
            if (iswupper(c)) c = towupper(c);
            size_t index = occurences.find(c);
            if (index != std::string::npos) freq.alphabet[index]++; 
        }
        freq.count++;
    }
    freq.frequency = calculateFreq(freq);
    return freq;
}


bool compareWstring(std::pair<double, wchar_t> lv, std::pair<double, wchar_t> rv)
{
    return lv.first > rv.first;
}

std::wstring orderedString(alphabetStatistics stats)
{
    std::wstring value;
    size_t len = stats.occurencies.length();
    std::pair<double, wchar_t> *pairt = new std::pair<double, wchar_t>[len];
    for (size_t i = 0; i < len; i++) {
        pairt[i] = std::make_pair(stats.frequency[i], stats.occurencies[i]);
    }
    sort(pairt, pairt + len, compareWstring);
    for (size_t i = 0; i < len; i++) {
        if (pairt[i].first != 0.)
            value += pairt[i].second;
    }
    delete [] pairt;
    return value;
}