// Person.cpp
#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, int acc_number, double initial_balance)
    : name(name), account(acc_number, initial_balance) {}

void Person::displayMenu() const {
    std::cout << "Welcome " << name << " What would you like to do? " << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "1: Deposit" << std::endl;
    std::cout << "2: Withdraw" << std::endl;
    std::cout << "3: Print Balance" << std::endl;
    std::cout << "4: Show Transaction History" << std::endl;
    std::cout << "5: Exit" << std::endl;
}

int Person::getUserChoice() const {
    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << std::endl;
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard any extra input
            std::cout << "=========================================\n";
            return choice;
        }
    }
}

void Person::processChoice(int choice) {
    double amount;
    switch (choice) {
    case 1:
        std::cout << "Enter amount to deposit: ";
        std::cin >> amount;
        account.deposit(amount);
        break;
    case 2:
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;
        account.withdraw(amount);
        break;
    case 3:
        account.printBalance();
        break;
    case 4:
        account.printTransactionHistory();
        break;
    case 5:
        std::cout << "Exiting the program." << std::endl;
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }
}