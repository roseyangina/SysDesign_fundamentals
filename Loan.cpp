#include "Loan.h"
#include <sstream>

// Constructor implementation
Loan::Loan(const std::string &id, double principal, double rate, int months, Customer* cust)
    : loanID(id), principalAmount(principal), interestRate(rate), duration(months), customer(cust), balance(0), approved(false) {
    loanStartDate = std::time(nullptr);  // Set the loan start date to the current
}

// Method to approve the loan with credit score check
bool Loan::approveLoan() {
    if (customer->getCreditScore() < 600) {  // Check if credit score is below 600
        approved = false;
        return false;  
    }
    // Adjust the interest rate based on credit score
    if (customer->getCreditScore() >= 750) {
        interestRate = 0.03;  // 3% for excellent credit
    } else if (customer->getCreditScore() >= 700) {
        interestRate = 0.04;  // 4% for good credit
    } else {
        interestRate = 0.05;  // 5% for fair credit
    }

    approved = true;
    balance = principalAmount + calculateInterest();
    return true;  // Loan is approved
}

double Loan::calculateInterest() const {
    return principalAmount * interestRate * (duration / 12.0); 
}

void Loan::repayLoan(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        balance = 0;
    }
}

std::string Loan::getLoanDetails() const {
    std::ostringstream details;
    details << "Loan ID: " << loanID << "\n"
            << "Principal Amount: " << principalAmount << "\n"
            << "Interest Rate: " << interestRate << "\n"
            << "Duration: " << duration << " months\n"
            << "Balance: " << balance << "\n"
            << "Start Date: " << std::ctime(&loanStartDate);
    return details.str();
}

std::string Loan::getLoanID() const {
    return loanID;
}

double Loan::getBalance() const {
    return balance;
}

std::time_t Loan::getLoanStartDate() const {
    return loanStartDate;
}

bool Loan::isApproved() const {
    return approved;
}

double Loan::getInterestRate() const {  // <--- Getter for interest rate
    return interestRate;
}