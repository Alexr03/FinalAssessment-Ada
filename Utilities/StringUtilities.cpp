//
// Created by Alex on 01/11/2019.
//

#include <algorithm>
#include <utility>
#include "StringUtilities.h"

string StringUtilities::convertToLowerCase(string word) {
    std::for_each(word.begin(), word.end(), [](char &c) {
        c = ::tolower(c);
    });

    return word;
}

string StringUtilities::trim(string str) {
    string chars = "\t\n\v\f\r";
    str.erase(0, str.find_first_not_of(chars));
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string StringUtilities::replaceAll(std::string str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

string StringUtilities::reverse(string str) {
    string reversed = std::move(str);
    std::reverse(reversed.begin(), reversed.end());

    return reversed;
}

string StringUtilities::convertToUpperCase(string word) {
    std::for_each(word.begin(), word.end(), [](char &c) {
        c = ::toupper(c);
    });

    return word;
}

string StringUtilities::sortAlphabetically(string word) {
    string sortedWord = word;
    sort(sortedWord.begin(), sortedWord.end());
    return sortedWord;
}
