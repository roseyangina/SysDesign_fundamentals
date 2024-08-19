#include "SavingsAccount.h"

//Constructor implementation

SavingsAccount::SavingsAccount(const std::string &accNumber, double initialBalance, double rate)
    : Account(accNumber, initialBalance, "Savings"), interestRate(rate) {} //this line calls and initializes the base class Account constructor
//SavingsAccount is inheriting from Account
// The colon is used to call the base class constructor and initialize the base class members so that the derived class can use them

void SavingsAccount::applyInterest(){
    balance = balance + balance * interestRate;
}

//Override the withdraw method from the Account class
void SavingsAccount::withdraw(double money){
    //calling the withdraw method from the base class
    Account::withdraw(money); 
}

