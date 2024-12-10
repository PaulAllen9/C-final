#include "TransactionLog.h"

TransactionLog::TransactionLog() {
	for (int i = 0; i < history_size; ++i) {
		history[i] = nullptr;
	}

}
TransactionLog::TransactionLog(int account_number)
	:account_number(account_number)
{
	//I dont think we need anything here.
	for (int i = 0; i < history_size; ++i) {
		history[i] = nullptr;
	}
}
void TransactionLog::add_transaction(Transaction t) {
	if (history_pointer < history_size) {
		history[history_pointer] = new Transaction(t); // Allocate new Transaction
		history_pointer++;
	}
	else {
		shift_log();
		history[history_size - 1] = new Transaction(t); // Allocate new Transaction
	}
}
void TransactionLog::set_account_number(int account_number)		{
	this->account_number = account_number;
}

void TransactionLog::set_name(std::string name) {
	//sets user name usually before use
	user = name;

}

void TransactionLog::get_deposits() {
	for (int i = 0; i < history_size; i++) {
		//std::cout << "Printing..." << std::endl;

		if (history[i] != nullptr && history[i]->get_action() == "deposit") {
			//std::cout << "inside..." << std::endl;

			history[i]->printString();
		}
	}
}
void TransactionLog::get_withdrawls() {
	for (int i = 0; i < history_size; i++) {
		if (history[i] != nullptr && history[i]->get_action() == "withdrawl") {
			std::cout << history[i]->toString() << std::endl;
		}
	}
}

void TransactionLog::get_history() {
	for (int i = 0; i < history_size; i++) {
		if (history[i] != nullptr) {

			std::cout << history[i]->toString() << std::endl;
		}
	}
}

void TransactionLog::withdrawl(double num) {
	add_transaction(Transaction("withdrawl", num));
}

void TransactionLog::deposit(double num) {
	add_transaction(Transaction("deposit", num));
}
void TransactionLog::shift_log() {
	delete history[0]; // Delete the first element
	for (int i = 1; i < history_size; i++) {
		history[i - 1] = history[i];
	}
	history[history_size - 1] = nullptr; // Set the last element to nullptr
}

TransactionLog::~TransactionLog()
{
	for (int i = 0; i < history_size; ++i) {
		delete history[i];
	}
}
