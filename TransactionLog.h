#pragma once
#include <string>
#include <iostream>
#include "UserAccount.h"
#include "Transaction.h"
class TransactionLog
{
	/*
	This class will store the transactions a user takes and store in an array
	*/
private:
	UserAccount user;
	//each user will save the last 20 transactions
	static const int history_size = 20;
	Transaction history[history_size];
	
public:
	//constructor brings user in
	TransactionLog(UserAccount user);


	std::string get_deposits();
	std::string get_withdrawls();
	std::string get_history();
	std::string withdrawl();
	std::string deposit();
};

