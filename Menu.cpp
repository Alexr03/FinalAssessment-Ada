//
// Created by Alex on 01/11/2019.
//

#include "Menu.h"
#include "Utilities/StringUtilities.h"
#include "Utilities/InputUtilities.h"
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

Menu::Menu(string word) {
    this->word = std::move(word);
}

void Menu::initializeMenu() {
    cout << "___Menu___" << endl;

    while(true){
        showMenuOptions();
        int optionChosen = InputUtilities::getResponseFiltered("Please choose an option from above: ", 6);
        if(optionChosen == 0){
            break;
        }
        executeMenuOptions(optionChosen);
    }
}

void Menu::showMenuOptions() {
    string options;
    options += "-------------------------------------------------------------------------------------\n";
    options += "0) Quit.\n";
    options += formatOption("1) Reverse the word {word}\n", word);
    options += formatOption("2) Convert {word} to UPPERCASE\n", word);
    options += formatOption("3) Convert {word} to lowercase\n", word);
    options += formatOption("4) Sort {word} in alphabetical order\n", word);
    options += formatOption("5) Show all possible anagrams of {word}\n", word);

    cout << options;
}

string Menu::formatOption(string option, const string& word) {
    return StringUtilities::replaceAll(std::move(option), "{word}", word);
}

void Menu::executeMenuOptions(int i) {
    switch (i){
        case 1:{
            cout << word << " reversed is: " << StringUtilities::reverse(word) << endl;
            break;
        }
        case 2:{
            cout << word << " to UPPERCASE is: " << StringUtilities::convertToUpperCase(word) << endl;
            break;
        }
        case 3:{
            cout << word << " to lowercase is: " << StringUtilities::convertToLowerCase(word) << endl;
            break;
        }
        case 4:{
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());

            cout << word << " sorted alphabetically is: " << sortedWord << endl;
            break;
        }
        case 5:{
            break;
        }
        default:{
            cout << i << " is not a valid option!\n";
        }
    }
}
