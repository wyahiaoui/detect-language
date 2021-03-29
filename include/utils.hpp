#ifndef LEVENSHTEIN_HPP
#define LEVENSHTEIN_HPP 1

#include <string>

// src http://letterfrequency.org/letter-frequency-by-language/

extern const wchar_t *english;
extern const wchar_t *german;
extern const wchar_t *french;
extern const wchar_t *spanish;

struct languagesParameters {
    std::wstring name;
    std::vector<double> frequencies;
};

struct  dictionaryParameters 
{
    dictionaryParameters() {
            width = 0;
            allLetters = L"";
            languages = NULL;
    }
    ~dictionaryParameters() {

    }
    languagesParameters *languages;
    std::wstring allLetters;
    size_t width;
    void supportedLanguages();
};


dictionaryParameters readDictionary(const char *filename);
int compareSeq(std::wstring seq1, std::wstring seq2);
std::wstring readFile(const char *filename);
#endif