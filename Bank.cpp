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
{}
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
		getline(ss, password, ',');

		manager_accounts[index++] = new Manager(accountNumber, firstName, lastName, password);
	}
	managerFile.close();
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
			return user_list[i];
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
		sign_in_user();
		break;
	case 2:
		create_user();
		break;
	case 3:
		sign_in_manager();
		break;
	case 4:
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
void Bank::view_user_data(int account_number) {
	for (int i = 0; i < user_list_size; ++i) {
		if (user_list[i] != nullptr && user_list[i]->get_account_number() == account_number) {
			user_list[i]->toString();
		}
	}
}

void Bank::sign_in_manager() {
	int accountNumber;
	std::string password;
	//got rid of attempt tries because this is just a test app
	//irl we probably would have that to avoid a password guesser hack into an account

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;
	std::cout << "Enter password: ";
	std::cin >> password;

	Account* manager = find_manager(accountNumber);
	if (manager != nullptr && manager->get_password() == password) {
		std::cout << "Sign-in successful!" << std::endl;
		// Proceed with user functions
		manager->functions();
		signed_in_manager = manager;

	}
	else {
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
	post_accounts();

	//possible other duties?

}
//called in close_day
void Bank::post_accounts() {
	/*puts information into the appropriate txt file*/
	post_user_accounts();
	post_manager_accounts();

}
//called in post_accounts
void Bank::post_user_accounts() {
	//reading from text file
	std::ofstream userFile("user.txt");
	if (!userFile.is_open()) {
		std::cout << "Couldn't open user file!" << std::endl;
		return;
	}
	/*puts user information into the txt file*/
	userFile.close();
}
//called in post_accounts
void Bank::post_manager_accounts() {
	//reading from text file
	std::ofstream managerFile("manager.txt");
	if (!managerFile.is_open()) {
		std::cout << "Couldn't open manager file!" << std::endl;
		return;
	}
	/*puts manager information into the txt file*/
	managerFile.close();
}

Bank::~Bank() {

}