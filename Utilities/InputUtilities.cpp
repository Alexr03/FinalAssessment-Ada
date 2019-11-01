//
// Created by Student on 01/11/2019.
//

#include "InputUtilities.h"
#include "StringUtilities.h"
#include <iostream>
#include <string>

using namespace std;

std::string InputUtilities::getResponse(const std::string &question) {
    string response;

    while (response.empty()) {
        cout << question;
        cin >> response;
    }

    return response;
}

int InputUtilities::getResponseFiltered(const std::string &question, int maxValue) {
    while (true) {
        string response = getResponse(question);

        for (int i = 0; i <= maxValue; i++) {
            int responseConverted = std::stoi(response);
            if (responseConverted == i) {
                return i;
            }
        }
    }
}

bool InputUtilities::confirmationResponse(std::string question) {
    string response = StringUtilities::convertToLowerCase(getResponse(question));

    return response == "y" || response == "yes";
}
