// main.cpp
#include <iostream>
#include "Person.h"

int main() {
    Person person("David", 19880908, 0);
    int choice;

    do {
        person.displayMenu();
        choice = person.getUserChoice();
        person.processChoice(choice);
    } while (choice != 5);

    return 0;
}