#include "Transaction.h"
Transaction::Transaction() {

}





Transaction::Transaction(int account_number, std::string action, int amount) {
	/*
	basic constructor takes in action and amount
	input validation in account class
	*/
	this->action = action;
	this->amount = amount;
	//this->date_time = std::chrono::system_clock::now();
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
	//this->date_time = std::chrono::system_clock::now();

}
Transaction::Transaction(int accountNumber, std::string type, double amount, double balance)
	:account_number(accountNumber),action(type),amount(amount), temp_balance(balance)
{
}
int Transaction::get_account_number() {
	return account_number;
}

std::string Transaction::get_action() {
	return action;
}
int Transaction::get_amount() {
	return amount;
}
//std::string Transaction::get_date_time() {
//	std::time_t now_time = std::chrono::system_clock::to_time_t(date_time);
//	std::tm* tm_ptr = std::localtime(&now_time);
//
//
//	//converts time into specified format
//	std::ostringstream oss;
//	oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");
//	return oss.str();
//}

std::string Transaction::toString()
{
	//std::string temp_str = user + ":\t" + get_date_time() + ":\t" + get_action() + ":\t" + std::to_string(get_amount());
	//std::cout << "toString..." << std::endl;

	std::string temp_str = std::to_string(account_number) + ":\t" + get_action() + ":\t" + std::to_string(get_amount());
	//std::cout << "after..." << std::endl;

	return temp_str;
}

void Transaction::printString()
{
	//std::cout << "print_string..." << std::endl;

	std::cout << toString() << std::endl;
}
