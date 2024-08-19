#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
protected:
    std::string accountNumber;  //unique account number
    double balance;            //current account balance
    std::string accountType;   //savings or checking account

public:
//Constructor to initialize account with  initial account number, balancd and account type
    Account(const std:: string &accNumber, double initialBalance, const std::string &accType);
    //Method to deposit money into account
    void deposit(double money);
    //Method to withdraw money from account
    virtual void withdraw(double money);
    //Method to get current account balance
    double getBalance() const;
    //Method to get type of account
    std::string getAccountType() const;
    //Method to get the account number
    std::string getAccountNumber() const;
};
#endif // ACCOUNT_H
