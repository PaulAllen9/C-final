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
        outFile << get_account_number() << ", " << "deposit, " << num << ", " << balance << std::endl;
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
        outFile << get_account_number() <<", " << "withdraw, " << num << ", " << balance << std::endl;
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

void UserAccount::add_transaction(Transaction t)
{
    user_log.add_transaction(t);
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
    Account::toString();
    std::cout << "Balance: " << balance << std::endl;
}

// Print available functions
void UserAccount::functions() {
    //Account::functions();
    std::cout << "1: deposit" << std::endl;
    std::cout << "2: withdraw" << std::endl;
    std::cout << "3: balance" << std::endl;
    std::cout << "4: history" << std::endl;
    std::cout << "5: deposit history" << std::endl;
    std::cout << "6: withdrawl history" << std::endl;
    std::cout << "7: sign out" << std::endl;
    std::cout << "8: get functions" << std::endl;

}

// Sign out function
void UserAccount::sign_out() {
    std::ifstream infile("user.txt");
    std::ofstream outfile("temp.txt");

    std::string line;
    bool found = false;

    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        int accountNumber;
        std::string firstName, lastName, password;
        double balance;

        ss >> accountNumber;
        ss.ignore();
        getline(ss, firstName, ',');
        ss.ignore();
        getline(ss, lastName, ',');
        ss.ignore();
        getline(ss, password, ',');
        ss >> balance;

        if (accountNumber == this->get_account_number()) {
            balance = this->balance;
            outfile << accountNumber << ", " << firstName << ", " << lastName << ", " << this->get_password() << ", " << getBalance() << std::endl;
            found = true;
        }
        else {
            outfile << accountNumber << ", " << firstName << ", " << lastName << ", " << password << ", " << balance << std::endl;
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        std::remove("user.txt");
        std::rename("temp.txt", "user.txt");
        std::cout << "Sign out successful. User data updated.\n";
    }
    else {
        std::remove("temp.txt");
        std::cerr << "Account number not found. Sign out failed.\n";
    }

    std::cout << "Signing out...\n";
}
// Destructor
UserAccount::~UserAccount() {
    num_of_user_accounts--;
}