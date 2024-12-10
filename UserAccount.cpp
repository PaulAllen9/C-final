#include "UserAccount.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Default constructor
UserAccount::UserAccount() {
    std::cout << "Please enter your balance: ";
    std::cin >> balance;
    user_log.set_name(getFname() + " " + getLname());
    set_account_type("User_Account");
    num_of_user_accounts++;
    user_log.set_account_number(get_account_number());

}

// Constructor with parameters for reading from a file
UserAccount::UserAccount(int account_number, std::string firstName, std::string lastName, std::string password, int balance)
    : Account(account_number, firstName, lastName, password), balance(balance) {
    num_of_user_accounts++;
    user_log.set_account_number(get_account_number());
}

// Constructor with parameters for creating a new account
UserAccount::UserAccount(std::string firstName, std::string lastName, std::string password, int balance)
    : Account(firstName, lastName, password), balance(balance) {
    num_of_user_accounts++;
    user_log.set_account_number(get_account_number());
}

// Deposit function
int UserAccount::deposit(double num) {
    if (num <= 0) {
        std::cout << "Invalid deposit amount. Please enter a positive value.\n";
        return -1;
    }

    balance += num;
    user_log.deposit(num);

    // Update the user.txt file

    std::string line;

    std::ofstream outFile("transactions.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << get_account_number() << "deposit" << num << balance << std::endl;
        outFile.close();
    }
    else {
        std::cout << "Error opening user file for writing. Your account data will not save" << std::endl;
    }

    std::cout << "Deposit successful. New balance: $" << balance << std::endl;
    return 1;
}

// Withdraw function
int UserAccount::withdraw(double num) {
    if (num <= 0) {
        std::cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        return -1;
    }

    if (num > balance) {
        std::cout << "Insufficient funds. Withdrawal failed.\n";
        return -1;
    }

    balance -= num;
    user_log.withdrawl(num);

    // Update the user.txt file

    std::string line;

    std::ofstream outFile("transactions.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << get_account_number() << "withdraw" << num << balance << std::endl;
        outFile.close();
    }
    else {
        std::cout << "Error opening user file for writing. Your account data will not save" << std::endl;
    }

    std::cout << "Withdrawl successful. New balance: $" << balance << std::endl;
    return 1;
}

// Validate number function
double UserAccount::validate_number(double num) {
    if (num == -1) {
        std::cout << "Negative 1 is the exit key, would you like to continue? Y/N: ";
        std::string confirm;
        std::cin >> confirm;
        if (confirm == "Y" || confirm == "y") {
            return -1.0;
        }
    }
    if (num < 0) {
        std::cout << "You cannot enter a negative value, please try again or enter -1 to exit: ";
        double input_num;
        std::cin >> input_num;
        return validate_number(input_num);
    }
    return num;
}

// Get balance function
double UserAccount::getBalance() {
    return balance;
}

// Get transaction history
void UserAccount::getTransactionHistory() {
    user_log.get_history();
}

// Get deposits
void UserAccount::getDeposits() {
    user_log.get_deposits();
}

// Get withdrawals
void UserAccount::getWithdrawls() {
    user_log.get_withdrawls();
}

// Print account details
void UserAccount::toString() {
    std::cout << "Account_num: " << get_account_number() << std::endl;
    Account::toString();
    std::cout << "Balance: " << balance << std::endl;
}

// Print available functions
void UserAccount::functions() {
    Account::functions();
    std::cout << "1: deposit" << std::endl;
    std::cout << "2: withdraw" << std::endl;
    std::cout << "3: balance" << std::endl;
    std::cout << "4: history" << std::endl;
    std::cout << "5: deposit history" << std::endl;
    std::cout << "6: withdrawl history" << std::endl;
}

// Sign out function
void UserAccount::sign_out() {
    std::cout << "Signing out..." << std::endl;
}

// Destructor
UserAccount::~UserAccount() {
    num_of_user_accounts--;
}