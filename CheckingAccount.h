#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {

private:
    double overdraftLimit; // Overdraft limit for the checking account

public:
    //Constructor to initialize checking account
    CheckingAccount(const std::string &accNumber, double initialBalance, double overdraft);
    // Override withdraw method to handle overdraft
    void withdraw(double money) override;    

};

#endif

