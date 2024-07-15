#include "Account.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>




Account::Account(int acc_number, double initial_balance)
    : account_number(acc_number), account_balance(initial_balance) {}

int Account::getAccountNumber() const {
    return account_number;
}

double Account::getAccountBalance() const {
    return account_balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        account_balance += amount;

        // Formatting amount for transaction history
        std::ostringstream ss; //will format the trailing ceroes 

        ss << "Deposited: EUR " << std::fixed << std::setprecision(2) << amount;
        transaction_history.push_back(ss.str());

        // Using the formatted amount in console output
        std::cout << "You've successfully deposited: EUR " << std::fixed << std::setprecision(2) << amount << std::endl;// fix and setprecision will format the trailing ceroes 
        std::cout << "New account balance: EUR " << std::fixed << std::setprecision(2) << account_balance << std::endl;
    }
    else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
    std::cout << std::endl;
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= account_balance) {
        account_balance -= amount;

        // Formatting amount for transaction history
        std::ostringstream ss;

        ss << "Withdrew: EUR " << std::fixed << std::setprecision(2) << amount;
        transaction_history.push_back(ss.str());

        // Using the formatted amount in console output
        std::cout << "You've successfully withdrawn: EUR " << std::fixed << std::setprecision(2) << amount << std::endl;
        std::cout << "New account balance: EUR " << std::fixed << std::setprecision(2) << account_balance << std::endl;
    }
    else {
        std::cout << "Invalid or insufficient funds for withdrawal." << std::endl;
    }
    std::cout << std::endl;
}

void Account::printBalance() const {
    std::cout << "Current account balance: EUR " << std::fixed << std::setprecision(2) << account_balance << std::endl; // 
    std::cout << std::endl;
}

void Account::printTransactionHistory() const {
    std::cout << "Transaction History:" << std::endl;
    for (const auto& transaction : transaction_history) {
        std::cout << transaction << std::endl;
    }
    std::cout << std::endl;
}
