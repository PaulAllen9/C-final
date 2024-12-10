#pragma once
#include "Account.h"
#include "UserAccount.h"
#include <string>
#include "Bank.h"

static int num_of_manager_accounts = 0;

class Manager : public Account {
public:
    Manager();
    Manager(int account_number, std::string firstName, std::string lastName, std::string password);

    void create_user_account(Bank* bank);
    void delete_user_account(Bank* bank);
    void view_all_user_data(Bank* bank);
    void view_user_data(Bank* bank, int account_number);

    void toString();
    void functions();
    double validate_number(double num);

    void sign_out();

    ~Manager();
};