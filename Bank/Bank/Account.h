// Account.h
#pragma once
#include <iostream>
#include <vector>

class Account {
public:
    Account(int acc_number, double initial_balance);

    int getAccountNumber() const;
    double getAccountBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void printBalance() const;
    void printTransactionHistory() const;

private:
    int account_number;
    double account_balance;
    std::vector<std::string> transaction_history;
};