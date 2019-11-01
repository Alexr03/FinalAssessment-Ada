//
// Created by Alex on 01/11/2019.
//

#include "Menu.h"
#include "Utilities/StringUtilities.h"
#include "Utilities/InputUtilities.h"
#include "AnagramSolver.h"
#include <iostream>
#include <utility>

using namespace std;

Menu::Menu(string word) {
    this->word = std::move(word);
}

void Menu::initializeMenu() {
    while (true) {
        showMenuOptions();
        int optionChosen = InputUtilities::getResponseFiltered("Please choose an option from above: ", 6);
        if (optionChosen == 0) {
            //We do this here to prevent the warning about an endless loop.
            if (InputUtilities::confirmationResponse("Are you sure you wish to exit? "))
                break;
        }
        executeMenuOptions(optionChosen);
    }
}

void Menu::showMenuOptions() {
    string options;
    options += "-------------------------------------------------------------------------------------\n";
    options += formatOption("1. Change the current word ({word})\n", word);
    options += formatOption("2. Reverse the word {word}\n", word);
    options += formatOption("3. Convert {word} to UPPERCASE\n", word);
    options += formatOption("4. Convert {word} to lowercase\n", word);
    options += formatOption("5. Sort {word} in alphabetical order, ascending\n", word);
    options += formatOption("6. Show all possible anagrams of {word}\n", word);
    options += "\n0. Quit the program.\n";
    options += "\nThe last word returned was " + (lastWord.empty() ? word : lastWord) + "\n";

    cout << options;
}

string Menu::formatOption(string option, const string &word) {
    return StringUtilities::replaceAll(std::move(option), "{word}", word);
}

void Menu::executeMenuOptions(int i) {
    cout << "-----------------------------------------------------------------------" << endl;
    switch (i) {
        case 1: {
            this->word = InputUtilities::getResponse("Please enter a new word: ");
            break;
        }
        case 2: {
            lastWord = StringUtilities::reverse(word);
            cout << word << " reversed is: " << lastWord << endl;
            break;
        }
        case 3: {
            lastWord = StringUtilities::convertToUpperCase(word);
            cout << word << " to UPPERCASE is: " << lastWord << endl;
            break;
        }
        case 4: {
            lastWord = StringUtilities::convertToLowerCase(word);
            cout << word << " to lowercase is: " << lastWord << endl;
            break;
        }
        case 5: {
            lastWord = StringUtilities::sortAlphabetically(word);
            cout << word << " sorted alphabetically is: " << lastWord << endl;
            break;
        }
        case 6: {
            AnagramSolver anagramSolver = AnagramSolver(StringUtilities::convertToLowerCase(word));
            cout << "POSSIBLE ANAGRAMS" << endl;
            anagramSolver.printAllAnagrams();
            cout << "ENGLISH ANAGRAMS" << endl;
            anagramSolver.printEnglishAnagrams();
            break;
        }
        default: {
            cout << "Unfortunately " << i << " is not a valid option, please try again." << endl;
        }
    }

    cout << "-----------------------------------------------------------------------" << endl;
}
