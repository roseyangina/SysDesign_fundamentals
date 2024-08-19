#include "Bank.h"
#include <algorithm>

void Bank::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

Customer* Bank::findCustomer(const std::string &customerID) const {
    for (auto* customer : customers) {
        if (customer->getCustomerID() == customerID) {
            return customer;
        }
    }
    return nullptr;  // if the customer is not found
}

void Bank::removeCustomer(const std::string &customerID) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if ((*it)->getCustomerID() == customerID) {
            delete *it;          
            customers.erase(it);  
            break;  // Exit the loop after removing the customer
        }
    }
}

Loan* Bank::issueLoan(const std::string &loanID, double principal, int duration, Customer* customer) {
    double initialInterestRate = 0.05;  // Initial rate
    Loan* loan = new Loan(loanID, principal, initialInterestRate, duration, customer);

    if (loan->approveLoan()) {
        loans.push_back(loan);
        return loan;
    } else {
        delete loan;  // If the loan is not approved, cleaning up memory
        return nullptr;
    }
}

// List of all loans
const std::vector<Loan*>& Bank::getLoans() const {
    return loans;
}

// Destructor
Bank::~Bank() {
    for (auto* customer : customers) {
        delete customer;
    }
    for (auto* loan : loans) {
        delete loan;
    }
}
