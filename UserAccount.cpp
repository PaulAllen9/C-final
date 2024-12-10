#include "UserAccount.h"
#include "Account.h"
UserAccount::UserAccount() {
	//ask for the information to create an account then initialize the values
	std::cout << "Please enter your balance: " << std::endl;
	std::cin >> balance;
	//create the transaction log
	user_log.set_name(getFname() + " " + getLname());
	set_account_type("User_Account");
	num_of_user_accounts++;
}
UserAccount::UserAccount(int account_number, std::string firstName, std::string lastName, std::string password, int balance)
	: Account(account_number, firstName, lastName, password), balance(balance)

{
	// This constructor will only ever be used to read from a txt file and store into an array
	// It only represents accounts that were previously create
	num_of_user_accounts++;
}
UserAccount::UserAccount(std::string firstName, std::string lastName, std::string password, int balance)
	: Account(firstName, lastName, password), balance(balance)

{
	num_of_user_accounts++;
}


int UserAccount::deposit(double num) {
	/*
	this function will attempt to deposit a value into a users account
	it will validate the value and provide escape paths to exit.
	It should return 
	1 for successful deposit,
	-1 for user exited function
	
	*/
	//validate it is a postive number
	double success = validate_number(num);
	if (success == -1.0) {
		std::cout << "Canceling deposit..." << std::endl;
		return -1;
	}
	else {
		balance += num;
		user_log.deposit(num);
		return 1;
	}	
}


int UserAccount::withdraw(double num) {
	/*
	this function will attempt to withdraw a value from a users account
	it will validate the value and provide escape paths to exit.
	It should return
	1 for successful deposit,
	-1 for user exited function

	*/
	//validate it is a postive number
	double success;
	while ((success = validate_number(num)) < balance && success!=-1.0) {
		std::cout << "You do not have enough money to withdraw this amount, please try a different amount." << std::endl;
	}
	if (success == -1.0) {
		std::cout << "Canceling withdrawl..." << std::endl;
		return -1;
	}
	else {
		balance -= num;
		user_log.withdrawl(num);
		return 1;
	}
}
double UserAccount::validate_number(double num) {
	//this function will validate an entry to make sure it is not negative, or it will check for exit
	//will continually prompt until valid number is entered or exit key is entered.
	
	//perhaps need to add a limit of like 10 to avoid over processesing
	if (num == -1) {
		std::cout << "Negative 1 is the exit key, would you like to continue? Y/N" << std::endl;
		std::string confirm;
		std::cin >> confirm;
		if (confirm == "Y" || confirm == "y") {
			//user exited deposit function
			return -1.0;
		}
	}
	if (num < 0) {
		std::cout << "You cannot enter a negative value, please try again or enter -1 to exit." << std::endl;
		double input_num;
		std::cin >> input_num;
		return validate_number(input_num);
	}
	else {
		return num;
	}
}
double UserAccount::getBalance() {
	return balance;
}


void UserAccount::getTransactionHistory() {
	user_log.get_history();
}

void UserAccount::getDeposits() {
	user_log.get_deposits();
}
void UserAccount::getWithdrawls() {
	user_log.get_withdrawls();
}

void UserAccount::toString() {
	/*
	This will give all the same information as Basic class, and balance
	
	*/
	std::cout << "Account_num: " << get_account_number() << std::endl;
	Account::toString();
	std::cout << "Balance: " << balance << std::endl;

}
void UserAccount::functions() {
	/*
	Will have all the same functions as basic account and deposit, withdraw, view balance,
	and view transaction history(all, deposits, or withdrawls)
	*/
	Account::functions();
	std::cout << "Deposit: deposit " << std::endl;
	std::cout << "Withdraw: withdraw " << std::endl;
	std::cout << "View Balance: balance " << std::endl;
	std::cout << "View All Transaction History: history " << std::endl;
	std::cout << "View Deposit History: dh " << std::endl;
	std::cout << "View Withdrawl History: wh " << std::endl;

}

void UserAccount::sign_out(){
	//still unsure how to implement
}

UserAccount::~UserAccount(){
}