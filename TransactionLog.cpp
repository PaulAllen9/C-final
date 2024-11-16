#include "TransactionLog.h"
TransactionLog::TransactionLog() {
	this->user = user;
}
													
std::string TransactionLog::get_deposits() {
	//prints a list of all deposits made by a user
	for (int i = 0; i < history_size; i++) {
		if (history[i].get_action() == "deposit") {

			std::string temp_str = user.getFname() + ":\t" + history[i].get_date_time() + ":\t" + history[i].get_action() + ":\t" + std::to_string(history[i].get_amount());

			std::cout << temp_str << std::endl;
		}
	}
}
std::string TransactionLog::get_withdrawls() {
	//prints a list of all withdrawls made by a user

	for (int i = 0; i < history_size; i++) {
		if (history[i].get_action() == "withdrawl") {

			std::string temp_str = user.getFname()+":\t" + history[i].get_date_time() + ":\t" + history[i].get_action() + ":\t" + std::to_string(history[i].get_amount());

			std::cout << temp_str << std::endl;
		}
	}
}
std::string TransactionLog::get_history() {
	//prints a list of all transactions made by a user

	for (int i = 0; i < history_size;i++) {
		std::string temp_str = user.getFname() + ":\t" + history[i].get_date_time() + ":\t" + history[i].get_action() + ":\t" + std::to_string(history[i].get_amount());

		std::cout << temp_str << std::endl;
	}
}
std::string TransactionLog::withdrawl() {


}
std::string TransactionLog::deposit() {

}