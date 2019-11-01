//
// Created by Student on 01/11/2019.
//

#ifndef STRINGMANIPULATION_INPUTUTILITIES_H
#define STRINGMANIPULATION_INPUTUTILITIES_H

#include <string>
#include <iostream>

class InputUtilities {
public:
    static std::string getResponse(const std::string &question);

    static int getResponseFiltered(const std::string &question, int maxValue);

    static bool confirmationResponse(std::string question);
};


#endif //STRINGMANIPULATION_INPUTUTILITIES_H
