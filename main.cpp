#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Customer.h"
#include "Loan.h"
#include "Transaction.h"
/*
The main demonstrates the follwoing:
1. Creating a bank object
2. Creating a customer object and adding customers to the bank
3. Creating SavingsAccount and CheckingAccount objects and associating them with customers
4. Issuing loans to customers
5. Making transactions on the accounts
6. Displaying the details of customers, accounts, loans, and transactions
7. Removing a customer from the bank
8. Displaying information showing the details of customers, accounts, and loans. 

*/

int main() {
    // Step 1: Create a bank
    Bank myBank;

    // Step 2: Add customers
    Customer* customer1 = new Customer("C001", "John Doe", "100 Nemo St", 720);
    Customer* customer2 = new Customer("C002", "Jane Smith", "125 Dora St", 680);
    myBank.addCustomer(customer1);
    myBank.addCustomer(customer2);

    // Step 3: Open accounts for customers
    SavingsAccount* savings1 = new SavingsAccount("S001", 5000.0, 0.02);
    CheckingAccount* checking1 = new CheckingAccount("CH001", 2000.0, 500.0);
    customer1->addAccount(savings1);
    customer1->addAccount(checking1);

    SavingsAccount* savings2 = new SavingsAccount("S002", 3000.0, 0.03);
    customer2->addAccount(savings2);

    // Step 4: Issue loans to customers
    Loan* loan1 = myBank.issueLoan("L001", 10000, 24, customer1);
    Loan* loan2 = myBank.issueLoan("L002", 5000, 12, customer2);

    // Display loan details if approved
    if (loan1) {
        std::cout << "Loan approved for " << customer1->getName() << ":\n" << loan1->getLoanDetails() << "\n";
    } else {
        std::cout << "Loan not approved for " << customer1->getName() << ".\n";
    }

    if (loan2) {
        std::cout << "Loan approved for " << customer2->getName() << ":\n" << loan2->getLoanDetails() << "\n";
    } else {
        std::cout << "Loan not approved for " << customer2->getName() << ".\n";
    }

    // Step 5: Perform transactions
    savings1->deposit(1000);
    savings1->withdraw(200);
    checking1->withdraw(2500);  // This should account for the overdraft limit

    // Display account details
    std::cout << "Customer 1 Accounts:\n";
    for (auto* account : customer1->getAccounts()) {
        std::cout << "Account Type: " << account->getAccountType()
                  << ", Account Number: " << account->getAccountNumber()
                  << ", Balance: " << account->getBalance() << "\n";
    }

    // Step 6: Remove a customer
    myBank.removeCustomer("C002");

    // Step 7: Display remaining customers
    std::cout << "Remaining Customers in the Bank:\n";
    Customer* remainingCustomer = myBank.findCustomer("C001");
    if (remainingCustomer) {
        std::cout << "Customer ID: " << remainingCustomer->getCustomerID()
                  << ", Name: " << remainingCustomer->getName() << "\n";
    } else {
        std::cout << "Customer not found.\n";
    }
    
    //clean up
    // The bank destructor will automatically clean up the remaining customers and loans

    return 0;

}