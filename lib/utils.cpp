#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <codecvt>

#include "utils.hpp"


const wchar_t *english = L"etaoinsrhldcumfpgwybvkxjqz";
const wchar_t *german = L"enisratdhulcgmobwfkzvüpäßjöyqx";
const wchar_t *french = L"esaitnrulodcmpévqfbghjàxèyêzçôùâûîœwkïëüæñ";
const wchar_t *spanish = L"eaosrnidlctumpbgyívqóhfzjéáñxúüwk";


int smallest(int x, int y, int z){
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

std::wstring readFile(const char *filename)
{
    std::wifstream file(filename, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<wchar_t> buffer(size);
    if (file.read(buffer.data(), size))
    {
        return buffer.data();
    }   
    return L"";
}

void gSupportedLanguages(dictionaryParameters dict)
{
    std::wcout << L"Litterally " << dict.allLetters << "\n";
    for (size_t i = 0; i < dict.width; i++) {
        languagesParameters language = dict.languages[i];
        std::wcout << "Language: " << language.name << "\n";
        for (size_t j = 0; j < language.frequencies.size(); j++) {
            std::wcout << dict.allLetters[j] << ": " << language.frequencies[j] << " ";
        }
        std::wcout << "\n\n";
    }
    std::wcout << "\n";
}

void dictionaryParameters::supportedLanguages() 
{
    gSupportedLanguages(*this);
}

std::vector<std::wstring> line_delimter(std::wstring input, std::wstring delimiter)
{
    size_t pos = 0;
    std::wstring token;
    std::vector<std::wstring> delimited;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        delimited.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    token = input.substr(0, pos);
    delimited.push_back(token);
    return delimited;
}

dictionaryParameters readDictionary(const char *filename) 
{
    std::wifstream infile(filename, std::ios::binary);
    infile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    dictionaryParameters dict;
    if (infile.is_open()){  
        std::wstring tp;
        std::getline(infile, tp);
        std::vector<std::wstring> languages = line_delimter(tp, L",");
        dict.width = languages.size() - 1;
        dict.languages = new languagesParameters[dict.width + 1];
        for (size_t i = 1; i < dict.width + 1; i++) {
            dict.languages[i - 1].name = languages[i];
        }
        while(!infile.eof()){
            std::getline(infile, tp);
            std::vector<std::wstring> line = line_delimter(tp, L",");
            dict.allLetters += line[0];
            for (size_t i = 1; i < line.size(); i++) {
                double freq = (double) wcstod(line[i].c_str(), 0);
                dict.languages[i - 1].frequencies.push_back(freq/100);
            }
        }
        infile.close();
    }  
    return dict;
}



int compareSeq(std::wstring seq1, std::wstring seq2) {

    size_t size_x = seq1.length() + 1;
    size_t size_y = seq2.length() + 1;
    int **matrix = new int*[size_x];
    for (size_t i = 0; i < size_x; i++) {
        matrix[i] = new int[size_y];
    }
    for (size_t i = 0; i < size_x; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j < size_y; j++) {
        matrix[0][j] = j;
    }
    for (size_t i = 1; i < size_x; i++) {
        for (size_t j = 1; j < size_y; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = smallest(matrix[i - 1][j] + 1, matrix[i - 1][j - 1], matrix[i][j - 1] + 1);
            }
            else {
                matrix[i][j] = smallest(matrix[i - 1][j] + 1, matrix[i - 1][j - 1] + 1, matrix[i][j - 1] + 1);
            }
        }
    }
    return matrix[size_x - 1][size_y - 1];
}


