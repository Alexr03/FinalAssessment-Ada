//
// Created by Alex on 01/11/2019.
//

#ifndef STRINGMANIPULATION_STRINGUTILITIES_H
#define STRINGMANIPULATION_STRINGUTILITIES_H

#include <string>
#include <iostream>

using namespace std;

class StringUtilities {
public:
    static string convertToLowerCase(string str);

    static string convertToUpperCase(string str);

    static string sortAlphabetically(string str);

    static string trim(string str);

    static string reverse(string str);

    static string replaceAll(string str, const string &from, const string &to);
};


#endif //STRINGMANIPULATION_STRINGUTILITIES_H
