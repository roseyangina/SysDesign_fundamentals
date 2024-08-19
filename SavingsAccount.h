#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

//Derived class to represent a savings account

class SavingsAccount : public Account{ //Inheritance
private:    
    double interestRate;
public:
    //Constructor to initialize savings account with account number, balance, interest rate
    SavingsAccount(const std::string &accNumber, double initialBalance, double rate);

    void applyInterest();

    // Override withdraw method from Account class
    void withdraw(double money) override;
};

#endif

