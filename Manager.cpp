#include "Manager.h"
#include "Bank.h"
#include <iostream>

// Default constructor
Manager::Manager() {
    num_of_manager_accounts++;
    set_account_type("Manager_Account");
}

// Constructor with parameters
Manager::Manager(int account_number, std::string firstName, std::string lastName, std::string password)
    : Account(account_number, firstName, lastName, password) {
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

    bank->delete_user(find_number);
}

void Manager::view_all_user_data(Bank* bank) {
    bank->view_all_user_data();
}

void Manager::view_user_data(Bank* bank, int account_number) {
    bank->view_user_data(account_number);

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
    std::cout << "5. Get Functions" << std::endl;

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