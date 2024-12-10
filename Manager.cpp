#include "Manager.h"
#include "Bank.h"
#include <iostream>

// Default constructor
Manager::Manager() {
    num_of_manager_accounts++;
    set_account_type("Manager_Account");
}

// Constructor with parameters
Manager::Manager(int accountNumber, std::string firstName, std::string lastName, std::string password)
    : Account(accountNumber, firstName, lastName, password) {
    num_of_manager_accounts++;
    set_account_type("Manager_Account");
}

void Manager::create_user_account(Bank* bank) {
    bank->create_user();
   
}

void Manager::delete_user_account(Bank* bank) {
    int find_number;
    std::cout << "Please enter the account number of the user you would like to delete: ";
    std::cin >> find_number;

    Account* temp_account = bank->find_user(find_number);
    if (temp_account != nullptr) {
        // Find the index of the account in the user_list array
        for (int i = 0; i < bank->user_list_size; ++i) {
            if (bank->user_list[i] == temp_account) {
                delete bank->user_list[i];
                bank->user_list[i] = nullptr; // Set the pointer to nullptr to avoid dangling pointers
                std::cout << "User account deleted successfully!" << std::endl;
                return;
            }
        }
    }
    else {
        std::cout << "User account not found." << std::endl;
    }
}

void Manager::view_all_user_data(Bank* bank) {
    for (int i = 0; i < Bank::user_list_size; ++i) {
        if (bank->user_list[i] != nullptr) {
            bank->user_list[i]->toString();
        }
    }
}

void Manager::view_user_data(Bank* bank, int accountNumber) {
    for (int i = 0; i < Bank::user_list_size; ++i) {
        if (bank->user_list[i] != nullptr && bank->user_list[i]->get_account_number() == accountNumber) {
            bank->user_list[i]->toString();
            return;
        }
    }

    std::cout << "User account not found." << std::endl;
}

void Manager::toString() {
    Account::toString();
}

void Manager::functions() {
    std::cout << "Manager Functions:" << std::endl;
    std::cout << "1. Create User Account" << std::endl;
    std::cout << "2. Delete User Account" << std::endl;
    std::cout << "3. View All User Data" << std::endl;
    std::cout << "4. View User Data" << std::endl;
}

double Manager::validate_number(double num) {
    if (num < 0) {
        std::cout << "Invalid number!" << std::endl;
        return -1;
    }
    return num;
}

void Manager::sign_out() {
    std::cout << "Signing out..." << std::endl;
}

Manager::~Manager() {
    num_of_manager_accounts--;
}