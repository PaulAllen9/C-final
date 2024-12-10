#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
class TransactionLog
{
	/*
	This class will store the transactions a user takes and store in an array
	*/
private:
	std::string user;
	//each user will save the last 20 transactions
	static const int history_size = 20;
	//an array of transactions
	Transaction history[history_size];
	//will represent one less than the latest most transaction
	//if 0 then no transactions have happened yet
	int history_pointer=0;
	
public:
	//constructor brings user in
	TransactionLog();
	
	void set_name(std::string name);
	void get_deposits();
	void get_withdrawls();
	void get_history();
	void withdrawl(double num);
	void deposit(double num);
	void shift_log();
};

