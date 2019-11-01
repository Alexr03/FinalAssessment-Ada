//
// Created by Alex on 01/11/2019.
//

#ifndef STRINGMANIPULATION_ANAGRAMSOLVER_H
#define STRINGMANIPULATION_ANAGRAMSOLVER_H


#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>

class AnagramSolver {

public:
    void printAllAnagrams();
    void printEnglishAnagrams();

    explicit AnagramSolver(std::string word);

private:
    std::vector<std::string> generateEnglishDictionary();
    void generatePossibleAnagrams(std::string str, int startIndex);
    std::vector<std::string> englishWords;
    std::vector<std::string> possibleAnagrams;
};


#endif //STRINGMANIPULATION_ANAGRAMSOLVER_H
