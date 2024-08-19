#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <ctime>
#include "Customer.h"

class Loan {
private:
    std::string loanID;        // Unique identifier for the loan
    double principalAmount;    // Principal amount of the loan
    double interestRate;       // Interest rate applied to the loan
    int duration;              // Duration of the loan in months
    Customer* customer;        // The customer who took the loan
    double balance;            // Current balance of the loan (including interest)
    std::time_t loanStartDate; // The date the loan was approved
    bool approved;             // Whether the loan is approved or not

public:
    // Constructor to initialize a loan
    Loan(const std::string &id, double principal, double rate, int months, Customer* cust);

    // Method to approve the loan
    bool approveLoan();

    // Method to calculate interest over the loan period
    double calculateInterest() const;

    // Method to make a repayment
    void repayLoan(double amount);

    // Method to get loan details
    std::string getLoanDetails() const;

    // Getters for loan attributes
    std::string getLoanID() const;
    double getBalance() const;
    std::time_t getLoanStartDate() const;
    bool isApproved() const;
    double getInterestRate() const; 
};

#endif // LOAN_H
