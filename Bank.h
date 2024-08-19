#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Customer.h"
#include "Loan.h"
#include "Transaction.h"

// Class representing the bank
class Bank {
private:
    std::vector<Customer*> customers;   // List of customers in the bank
    std::vector<Loan*> loans;           // List of loans issued by the bank

public:
    // Method to add a customer to the bank
    void addCustomer(Customer* customer);

    // Method to find a customer by their ID
    Customer* findCustomer(const std::string &customerID) const;

    // Method to remove a customer from the bank
    void removeCustomer(const std::string &customerID);

    // Method to issue a loan to a customer
    Loan* issueLoan(const std::string &loanID, double principal, int duration, Customer* customer);

    // Method to get a list of all loans
    const std::vector<Loan*>& getLoans() const;

    // Destructor to clean up dynamically allocated memory
    ~Bank();
};

#endif // BANK_H
