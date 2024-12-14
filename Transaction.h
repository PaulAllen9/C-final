#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>

#include <chrono>
#include <ctime>
class Transaction {
private:
	//will be either withdraw or deposit
	int account_number;
	std::string action;
	//the amount of the transaction
	//all deposits will be positive,
	//all withdrawls should be negative
	double amount;
	double temp_balance;
	//will provide the date_time in format 
	//day_of_week, month, number_day, hour:minute:sec, year
	//std::chrono::time_point<std::chrono::system_clock> date_time;

public:
	Transaction();
	Transaction(int account_number, std::string action, int amount);
	Transaction(double amount);
	Transaction(int accountNumber, std::string type, double amount, double balance);
	int get_account_number();
	std::string get_action();
	int get_amount();
	//std::string get_date_time();
	std::string toString();
	void printString();

};