#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"

// Class representing a bank customer
class Customer {
private:
    std::string customerID;           // Unique id for the customer
    std::string name;                 // Customer's name
    std::string address;              // Customer's address
    std::vector<Account*> accounts;   // List of accounts associated with the customer
    int creditScore;                  // Customer's credit score (for loan approval)

public:
    // Constructor to initialize a customer with their id, name and address
    Customer(const std::string &id, const std::string &custName, const std::string &custAddress, int score);

    // Method to add account, remove account and get a list of their accounts
    void addAccount(Account* account);

    void removeAccount(const std::string &accountNumber);

    const std::vector<Account*>& getAccounts() const; 

    // Method to get the customer's ID, name and address
    std::string getCustomerID() const;

    std::string getName() const;

    std::string getAddress() const;

    // Method to get the customer's credit score
    int getCreditScore() const;
};

#endif // CUSTOMER_H
