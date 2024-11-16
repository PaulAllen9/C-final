#include "Transaction.h"
#include <iomanip>
#include <sstream>


Transaction::Transaction(std::string action, double amount) {
	/*
	basic constructor takes in action and amount
	input validation in account class
	*/
	this->action = action;
	this->amount = amount;
	this->date_time = std::chrono::system_clock::now();
}
Transaction:: Transaction(double amount) {
	//this constructor only takes in the amount.
	//if negative represents a withdrawl
	//if postive represents a deposit
	this->amount = amount;
	if (amount > 0) {
		this->action = "deposit";
	}
	else {
		this->action = "withdrawl";

	}
	this->date_time = std::chrono::system_clock::now();

}
std::string Transaction::get_action() {
	return action;
}
double Transaction::get_amount() {
	return amount;
}
std::string Transaction::get_date_time() {
	std::time_t now_time = std::chrono::system_clock::to_time_t(date_time);
	std::tm* tm_ptr = std::localtime(&now_time);


	//converts time into specified format
	std::ostringstream oss;
	oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");
	return oss.str();
}
