#include "Transaction.h"
#include <sstream>

// Constructor implementation
Transaction::Transaction(const std::string &T_id, double T_amnt, const std::string &T_type) 
: transactionID(T_id), amount(T_amnt), transactionType(T_type) {
    date = std::time(nullptr);      // Set the transaction date to the current time
}

std::string Transaction::getTransactionDetails() const {
    std::ostringstream details;
    details << "Transaction ID: " << transactionID << "\n"
            << "Date: " << std::ctime(&date)
            << "Amount: " << amount << "\n"
            << "Type: " << transactionType << "\n";
    return details.str();
}

std::string Transaction::getTransactionID() const {
    return transactionID;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTransactionType() const {
    return transactionType;
}

std::time_t Transaction::getDate() const {
    return date;
}