#pragma once
#include <string>

#include <chrono>
#include <ctime>
class Transaction {
private:
	//will be either withdraw or deposit
	std::string action;
	//the amount of the transaction
	//all deposits will be positive,
	//all withdrawls should be negative
	int amount;

	//will provide the date_time in format 
	//day_of_week, month, number_day, hour:minute:sec, year
	std::chrono::time_point<std::chrono::system_clock> date_time;

public:
	Transaction(std::string action, int amount);
	Transaction(int amount);
	std::string get_action();
	int get_amount();
	std::string get_date_time();

};