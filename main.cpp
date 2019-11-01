#include <iostream>
#include "Menu.h"
#include "Utilities/InputUtilities.h"

int main() {
    string word = InputUtilities::getResponse("Please enter a word to get started: ");
    Menu menu = Menu(word);
    menu.initializeMenu();

    return 0;
}
