#include "Customer.h"
#include <algorithm>

// Constructor implementation
Customer::Customer(const std::string &id, const std::string &custName, const std::string &custAddress, int score)
    : customerID(id), name(custName), address(custAddress), creditScore(score) {}

// Add an account
void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

// Remove an account
void Customer::removeAccount(const std::string &accountNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getAccountNumber() == accountNumber) {  // iterate and compare the account numbers to find the account
            delete *it;          // Delete the account object to free up memory
            accounts.erase(it);  // Erase the account from the vector
            break;  // Exit the loop after removing the account
        }
    }
}

const std::vector<Account*>& Customer::getAccounts() const {
    return accounts;
}

std::string Customer::getCustomerID() const {
    return customerID;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

// Get the customer's credit score
int Customer::getCreditScore() const {  
    return creditScore;
}