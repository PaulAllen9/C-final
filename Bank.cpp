#include "Bank.h"
#include "UserAccount.h"
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//constructor to build a bank
Bank::Bank(std::string name)
	:bank_name(name)
	
{
	start_day();
}
//starting a day in the bank will consist of loading user and manager data into system for processing
void Bank::start_day() {
	load_accounts();

	//any other duties?

	start_page();

}
//called in start day
void Bank::load_accounts() {
	load_user_accounts();
	load_manager_accounts();
	load_transactions();
}
//called in load_accounts
void Bank::load_user_accounts() {
	std::ifstream userFile("user.txt");
	if (!userFile.is_open()) {
		std::cout << "Couldn't open user file!" << std::endl;
		return;
	}

	std::string bankLine;
	int index = 0;
	while (getline(userFile, bankLine) && index < user_list_size) {
		std::stringstream ss(bankLine);
		int accountNumber;
		std::string firstName, lastName, password;
		double balance;

		ss >> accountNumber;
		ss.ignore();
		getline(ss, firstName, ',');
		ss.ignore();
		getline(ss, lastName, ',');
		ss.ignore();
		getline(ss, password, ',');
		ss >> balance;

		//put the data into the array created in the constructor for easy manipulation and access
		user_list[index++] = new UserAccount(accountNumber, firstName, lastName, password, balance);
	}
	userFile.close();
}
//called in load_accounts
void Bank::load_manager_accounts() {
	std::ifstream managerFile("manager.txt");
	if (!managerFile.is_open()) {
		std::cout << "Couldn't open manager file!" << std::endl;
		return;
	}

	std::string bankLine;
	int index = 0;
	while (getline(managerFile, bankLine) && index < manager_list_size) {
		std::stringstream ss(bankLine);
		int accountNumber;
		std::string firstName, lastName, password;

		ss >> accountNumber;
		ss.ignore();
		getline(ss, firstName, ',');
		ss.ignore();
		getline(ss, lastName, ',');
		ss.ignore();
		ss >> password;
		manager_accounts[index++] = new Manager(accountNumber, firstName, lastName, password);
	}
	managerFile.close();
}
void Bank::load_transactions() {
	std::ifstream transactionFile("transaction.txt");
	if (!transactionFile.is_open()) {
		std::cout << "Couldn't open transaction file!" << std::endl;
		return;
	}

	std::string transactionLine;
	int index = 0;
	while (getline(transactionFile, transactionLine) && index < transaction_list_size) {
		std::stringstream ss(transactionLine);
		int accountNumber;
		std::string type;
		int amount;
		double balance;

		ss >> accountNumber;
		ss.ignore();
		getline(ss, type, ',');
		ss.ignore();
		ss >> amount;
		ss.ignore();
		ss >> balance;

		transaction_list[index++] = new Transaction(accountNumber, type, amount, balance);
	}
	transactionFile.close();
}




Account* Bank::find_user(int account_number) {
	for (int i = 0; i < user_list_size; ++i) {
		if (user_list[i] != nullptr && user_list[i]->get_account_number() == account_number) {
			return user_list[i];
		}
	}
	return nullptr; // Account not found points to null
}
Account* Bank::find_manager(int account_number) {
	for (int i = 0; i < manager_list_size; ++i) {
		if (manager_accounts[i] != nullptr && manager_accounts[i]->get_account_number() == account_number) {
			return manager_accounts[i];
		}
	}
	return nullptr; // Account not found points to null
}

/*At this point the start page will launch
this provide options to login as a user or manager, create a user account, or exit the app*/
void Bank::start_page() {
	//will server as the hub for user interaction with the bank applicaiton
	//will still need to add formatting to make the app look presentable
	std::cout << "Welcome to the our bank, " << bank_name << "!" << std::endl;
	std::cout << "Functions:" << "Type to enact " << std::endl;

	std::cout << "To sign-in as user: " << "Press (1)" << std::endl;
	std::cout << "To create a user account: " << "Press (2)" << std::endl;
	std::cout << "To sign-in as manager: " << "Press (3)" << std::endl;
	std::cout << "To exit the applicaiton: " << "Press (4)" << std::endl;
	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "1" << std::endl;

		sign_in_user();
		break;
	case 2:
		std::cout << "2" << std::endl;
		create_user();
		break;
	case 3:
		std::cout << "3" << std::endl;
		sign_in_manager();
		break;
	case 4:
		std::cout << "4" << std::endl;

		exit();
		break;
	default:
		std::cout << "Invalid option. Please try again." << std::endl;
		start_page();
	}

}

void Bank::sign_in_user() {
	int accountNumber;
	std::string password;
	//got rid of attempt tries because this is just a test app
	//irl we probably would have that to avoid a password guesser hack into an account

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;
	std::cout << "Enter password: ";
	std::cin >> password;

	Account* user = find_user(accountNumber);
	if (user != nullptr && user->get_password() == password) {
		std::cout << "Sign-in successful!" << std::endl;
		// Proceed with user functions
		user->functions();
		signed_in_user = user;


		int choice;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		do{
		switch (choice) {
		case 1: {
			double amount;
			std::cout << "Enter amount to deposit: ";
			std::cin >> amount;
			dynamic_cast<UserAccount*>(user)->deposit(amount);
			break;
		}
		case 2: {
			double amount;
			std::cout << "Enter amount to withdraw: ";
			std::cin >> amount;
			dynamic_cast<UserAccount*>(user)->withdraw(amount);
			break;
		}
		case 3:
			std::cout << "Current balance: $" << dynamic_cast<UserAccount*>(user)->getBalance() << std::endl;
			break;
		case 4:
			dynamic_cast<UserAccount*>(user)->getTransactionHistory();
			break;
		case 5:
			dynamic_cast<UserAccount*>(user)->getDeposits();
			break;
		case 6:
			dynamic_cast<UserAccount*>(user)->getWithdrawls();
			break;
		case 7:
			std::cout << "Signing out...\n";
			dynamic_cast<UserAccount*>(user)->sign_out();
			break;
		case 8:
			std::cout << "Signing out...\n";
			dynamic_cast<UserAccount*>(user)->functions();
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 7);

	signed_in_user = nullptr;
	start_page();

	}
	else {
		std::cout << "Invalid account number or password." << std::endl;
		start_page();
	}
}

void Bank::create_user() {
	std::string firstName, lastName, password;
	double balance;

	// Collect user information
	std::cout << "Creating a new user account" << std::endl;
	std::cout << "Enter your first name: ";
	std::cin >> firstName;
	std::cout << "Enter your last name: ";
	std::cin >> lastName;
	std::cout << "Create a password: ";
	std::cin >> password;
	std::cout << "Enter the amount that you are putting into your brand new account: ";
	std::cin >> balance;

	// Validate initial balance
	if (balance < 0) {
		std::cout << "Initial balance cannot be negative. Setting to $0." << std::endl;
		balance = 0;
	}

	// Create a new UserAccount object
	UserAccount* newUser = new UserAccount(firstName, lastName, password, balance);
	int accountNumber = newUser->get_account_number();
	// Add the new user to the user_list array
	for (int i = 0; i < user_list_size; ++i) {
		if (user_list[i] == nullptr) {
			user_list[i] = newUser;
			break;
		}
	}

	// Append the new user to the user.txt file
	std::ofstream userFile("user.txt", std::ios::app);
	if (userFile.is_open()) {
		userFile << accountNumber << ", " << firstName << ", " << lastName << ", "
			<< password << ", " << balance << std::endl;
		userFile.close();
	}
	else {
		std::cout << "Error opening user file for writing. Your account data will not save" << std::endl;
	}

	std::cout << "Account created successfully!" << std::endl;
	std::cout << "Your account number is: " << accountNumber << std::endl;

	// Return to start page
	start_page();
}
void Bank::delete_user(int account_number) {
	for (int i = 0; i < user_list_size; ++i) {
		if (user_list[i] != nullptr && user_list[i]->get_account_number() == account_number) {
			delete user_list[i];
			user_list[i]=nullptr;
		}
	}
}
void Bank::view_all_user_data() {
	//prints a list of all user data
	for (int i = 0; i < user_list_size; ++i) {
		user_list[i]->toString();
	}
}
void Bank::view_all_transaction_data() {
	//prints a list of all user data
	for (int i = 0; i < user_list_size; ++i) {
		for (int j = 0; j < transaction_list_size; ++j) {
			if(transaction_list[j] != nullptr) {
				std::cout << transaction_list[j]->toString() << std::endl;
			}
			else {
				if (transaction_list[j] != nullptr) {
					break;
				}
			}
		}
	}
}

void Bank::view_transaction_data(int account_number)
{
	//prints a list of all user data
	for (int i = 0; i < user_list_size; ++i) {
		for (int j = 0; j < transaction_list_size; ++j) {
			if (transaction_list[j] != nullptr and transaction_list[j]->get_account_number() == user_list[i]->get_account_number()) {
				std::cout << transaction_list[j]->toString() << std::endl;
			}
			else {
				if (transaction_list[j] != nullptr) {
					break;
				}
			}
		}
	}
}


void Bank::view_user_data(int account_number) {
	for (int i = 0; i < user_list_size; ++i) {
		if (user_list[i] != nullptr && user_list[i]->get_account_number() == account_number) {
			user_list[i]->toString();
		}
	}
}

void Bank::view_all_manager_data() {
	//prints a list of all user data
	for (int i = 0; i < manager_list_size; ++i) {
		if (manager_accounts[i] != nullptr) {
			manager_accounts[i]->toString();
		}
		else
			break;
	}
}

void Bank::sign_in_manager() {
	int account_number;
	std::string password;
	//got rid of attempt tries because this is just a test app
	//irl we probably would have that to avoid a password guesser hack into an account

	std::cout << "Enter account number: ";
	std::cin >> account_number;
	std::cout << "Enter password: ";
	std::cin >> password;

	Account* manager = find_manager(account_number);
	if (manager != nullptr && manager->get_password() == password) {
		std::cout << "Sign-in successful!" << std::endl;
		// Proceed with user functions
		manager->functions();
		signed_in_manager = manager;

		int choice;
		do{
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			dynamic_cast<Manager*>(manager)->create_user_account(this);
			break;
		case 2:
			dynamic_cast<Manager*>(manager)->delete_user_account(this);
			break;
		case 3:
			dynamic_cast<Manager*>(manager)->view_all_user_data(this);
			break;
		case 4: {
			int user_account_number;
			std::cout << "Enter the account number of the user: ";
			std::cin >> user_account_number;
			dynamic_cast<Manager*>(manager)->view_user_data(this, user_account_number);
			break;
		}
		case 5:
			std::cout << "Signing out...\n";
			dynamic_cast<Manager*>(manager)->sign_out();
			break;
		case 6:
			std::cout << "Signing out...\n";
			dynamic_cast<Manager*>(manager)->functions();
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
		} while (choice != 5);
		signed_in_manager = nullptr;
		start_page();
	}
	else{
		std::cout << "Invalid account number or password." << std::endl;
		start_page();
	}
}

void Bank::exit()
{
	close_day();
	std::cout << "Thank you for using " << bank_name << "," << std::endl;
	std::cout << "Have a nice day!" << std::endl;
}
//happens when the user selects the exit option
//will save data then exit the terminal
void Bank::close_day() {
	//possible other duties?

}


Bank::~Bank() {

}