//
// Created by Alex on 01/11/2019.
//

#ifndef STRINGMANIPULATION_MENU_H
#define STRINGMANIPULATION_MENU_H

#include <string>

using namespace std;

class Menu {

public:
    string word;

    explicit Menu(string word);

    void initializeMenu();

private:
    void showMenuOptions();
    void executeMenuOptions(int option);
    static string formatOption(string option, const string& word);
};


#endif //STRINGMANIPULATION_MENU_H
