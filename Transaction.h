#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string transactionID;  // Unique id for the transaction
    std::time_t date;           // Date and time of the transaction
    double amount;              // Amount involved in the transaction
    std::string transactionType; // Type of transaction, i.e Deposit, Withdrawal

public:
    // Constructor to initialize a transaction
    Transaction(const std::string &T_id, double T_amnt, const std::string &T_type);

    // Method to get transaction details
    std::string getTransactionDetails() const;

    // Method to get transaction ID
    std::string getTransactionID() const;

    // Method to get the transaction amount
    double getAmount() const;

    // Method to get the transaction type
    std::string getTransactionType() const;

    // Method to get the transaction date
    std::time_t getDate() const;
};

#endif // TRANSACTION_H
