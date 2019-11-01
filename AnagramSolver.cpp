//
// Created by Alex on 01/11/2019.
//

#include "AnagramSolver.h"
#include "Utilities/StringUtilities.h"

AnagramSolver::AnagramSolver(std::string word) {
    cout << "Anagram Solver initialized. Please wait." << endl;
    this->englishWords = generateEnglishDictionary();
    generatePossibleAnagrams(word, 0);
    cout << "Anagram Solver Finished Initialization" << endl;
}

std::vector<std::string> AnagramSolver::generateEnglishDictionary() {
    std::vector<std::string> dictionary;
    std::ifstream englishDictionary("words_alpha.txt");

    for (std::string line; getline(englishDictionary, line);) {
        dictionary.push_back(StringUtilities::trim(line));
    }

    return dictionary;
}

void AnagramSolver::generatePossibleAnagrams(string str, int startIndex) {
    int endIndex = str.size() - 1;
    if (startIndex == endIndex) {
        if (find(this->possibleAnagrams.begin(), this->possibleAnagrams.end(), str) == this->possibleAnagrams.end()) {
            this->possibleAnagrams.push_back(str);
        }
    }

    for (int i = startIndex; i <= endIndex; i++) {
        swap(str[startIndex], str[i]);
        this->generatePossibleAnagrams(str, startIndex + 1);
        swap(str[startIndex], str[i]);
    }
}

void AnagramSolver::printAllAnagrams() {
    for (const auto& anagram : this->possibleAnagrams) {
        cout << anagram << endl;
    }
}

void AnagramSolver::printEnglishAnagrams() {
    for (const auto& anagram : this->possibleAnagrams) {
        bool isEnglishWord = find(englishWords.begin(), englishWords.end(), anagram) != englishWords.end();
        if (isEnglishWord) {
            cout << anagram << endl;
        }
    }
}