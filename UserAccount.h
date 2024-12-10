#pragma once
#include "Account.h"
#include "TransactionLog.h"
#include <string>

//inherits from account
static int num_of_user_accounts = 0;
class UserAccount:public Account
{
private:
	double balance;
	TransactionLog user_log;
public:

	UserAccount();
	UserAccount(Account account);
	UserAccount(std::string firstName, std::string lastName, std::string password, int balance);
	UserAccount(int accountNumber, std::string firstName, std::string lastName, std::string password, int balance);


	int deposit(double num);
	int withdraw(double num);
	double getBalance();

	void getTransactionHistory();
	void getDeposits();
	void getWithdrawls();



	void toString();
	void functions();
	double validate_number(double num);

	void sign_out();

	~UserAccount();
};

