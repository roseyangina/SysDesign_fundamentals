#include "CheckingAccount.h"
#include <iostream>

// Constructor implementation
// Constructor implementation
CheckingAccount::CheckingAccount(const std::string &accNumber, double initialBalance, double overdraft)
    : Account(accNumber, initialBalance, "Checking")  // Initialize the base Account class
    , overdraftLimit(overdraft) {}                    // Initialize the overdraft limit

// Override withdraw method to allow overdraft
void CheckingAccount::withdraw(double money) {
    if (money <= balance + overdraftLimit) {
        balance -= money;
    } else {
        std::cout << "Overdraft limit exceeded" << std::endl;
    }
}