// Person.h
#pragma once
#include "Account.h"
#include <string>

class Person {
public:
    Person(const std::string& name, int acc_number, double initial_balance);

    void displayMenu() const;
    int getUserChoice() const;
    void processChoice(int choice);

private:
    std::string name;
    Account account;
};
