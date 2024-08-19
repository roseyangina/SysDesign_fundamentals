#include "Account.h"
#include <iostream>

//The constructor implementation
Account::Account(const std::string &accNumber, double initialBalance, const std::string &accType)
{
    //initializing the account with the initial account number, balance and account type
    //we will pass in the values of the account number, balance and account type when we create an object of the Account class
    accountNumber = accNumber;
    balance = initialBalance;
    accountType = accType;
}

void Account::deposit(double money){ 
    // Account:: indicates that the deposit method belongs to the Account class
    balance += money;
}

void Account::withdraw(double money) {
    //a check for insufficient funds
    if(money <= balance)
    {
        balance -= money;
    }
    else{
        std::cout << "Insufficient funds" << std::endl;
    }
}

double Account::getBalance() const{
    return balance;
}

std::string Account::getAccountType() const{
    return accountType;
}

std::string Account::getAccountNumber() const {  
    return accountNumber;
}