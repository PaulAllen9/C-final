#include "TransactionLog.h"

TransactionLog::TransactionLog() {
	//I dont think we need anything here.
	std::cout << "Default transactionLog constructor" << std::endl;
}

void TransactionLog::set_name(std::string name) {
	//sets user name usually before use
	user = name;

}

std::string TransactionLog::get_deposits() {
	//prints a list of all deposits made by a user
	for (int i = 0; i < history_size; i++) {
		if (history[i].get_action() == "Deposit") {

			history[i].toString(user);
		}
	}
}
std::string TransactionLog::get_withdrawls() {
	//prints a list of all withdrawls made by a user

	for (int i = 0; i < history_size; i++) {
		if (history[i].get_action() == "Withdrawl") {

			history[i].toString(user);
		}
	}
}
std::string TransactionLog::get_history() {
	//prints a list of all transactions made by a user

	for (int i = 0; i < history_size; i++) {
		history[i].toString(user);
	}
}
void TransactionLog::withdrawl(double num) {
	//this function will add a withdrawl to the hisrtory
	if (history_pointer < 20) {
		//history is less than full
		history[history_pointer] = Transaction("Withdrawl", num);
	}
	else {
		//history is full
		//do a shift and put new data at the end
		shift_log();
		//replace history[history_size] with new transaction
		history[history_size-1]= Transaction("Withdrawl", num);
	}

}
void TransactionLog::deposit(double num) {
	//This function will add a deposit to the history
	if (history_pointer < 20) {
		//history is less than full
		history[history_pointer] = Transaction("Deposit", num);
	}
	else {
		//history is full
		//do a shift and put new data at the end
		shift_log();
		//replace history[history_size] with new transaction
		history[history_size - 1] = Transaction("Deposit", num);
	}

}

void TransactionLog::shift_log() {
	/*This function should delete the value at history[0] and then replace all values of history with the ones following it*/
	for (int i = 1; i < history_size-1; i++) {
		history[i - 1] = history[i];
	}
}