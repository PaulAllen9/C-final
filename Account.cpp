#include "Account.h"
Account::Account() {
	//ask for the information to create an account then initialize the values
	std::cout << "Please enter your first name: " << std::endl;
	std::cin >> fname;
	std::cout << "Please enter your last name: " << std::endl;
	//possibly use get line when they have a two part name
	std::cin >> lname;
	//create a simple password, im not worried about making something hard to guess
	std::cout << "Please create a password: " << std::endl;
	std::cin >> password;

	//adds to the count of running accounts
	num_of_basic_accounts++;
	//keeps tract of how many total accounts were ever created to then create ever increasing id numbers
	//will need to store in txt file and load in after loading all the accounts some how
	//perhaps just look at the last known number and start from there?
	numb_for_account_num++;
	account_number = numb_for_account_num;
}
Account::Account(std::string firstName, std::string lastName, std::string password)
	: fname(firstName), lname(lastName), password(password)
{
	//adds to the count of running accounts
	num_of_basic_accounts++;
	//keeps tract of how many total accounts were ever created to then create ever increasing id numbers
	//will need to store in txt file and load in after loading all the accounts some how
	//perhaps just look at the last known number and start from there?
	numb_for_account_num++;
	account_number = numb_for_account_num;

}
Account::Account(int accountNumber, std::string firstName, std::string lastName, std::string password)
	: account_number(accountNumber), fname(firstName), lname(lastName), password(password)
{
	// If the account was already made and does not need a new account number
	// If this is called, it is being called to read from a file
	//adds to the count of running accounts
	num_of_basic_accounts++;
	//keeps tract of how many total accounts were ever created to then create ever increasing id numbers
	//will need to store in txt file and load in after loading all the accounts some how
	//perhaps just look at the last known number and start from there?
	numb_for_account_num++;
	account_number = numb_for_account_num;
}




void Account::toString() {
	//prints all the information in an account
	//make it when called in child class, the child class can simply continue the pattern

	std::cout << "Account number: " << account_number << std::endl;
	std::cout << "User: " << fname << " " << lname <<":" << std::endl;
	std::cout << "Account Type: " << account_type << std::endl;
	std::cout << "Password: " << password << std::endl;
}
void Account::functions() {
	//displays a list of all the functions that account can do
	
	std::cout << "Function name: Enter text to start function " << std::endl;
	//all functions allowed by user on base account
	std::cout << "Change name: name " << std::endl;
	std::cout << "Change first name: first " << std::endl;
	std::cout << "Change last name: last " << std::endl;
	std::cout << "Get Functions: Help " << std::endl;
}
int Account::get_account_number() {
	return account_number;
}

std::string Account::get_password() {
	return password;
}
void Account::set_password(std::string pass) {
	password = pass;
}




void Account::setFname(std::string name) {
	//changes the account first name
	fname = name;

}
std::string Account::getFname() {
	//returns first name
	return fname;

}
void Account::setLname(std::string name) {
	//changes the last name
	lname = name;
}
std::string Account::getLname() {
	//returns last name
	return lname;

}
void Account::set_account_type(std::string type) {
	//changes the account type
	//will be called in child classes to change type to their type
	account_type = type;
}
std::string Account::get_account_type() {
	//returns the type
	return account_type;
}

void Account::sign_out() {
	//don't need to implement due to pure virutalism
	//how to implement in other classes though?
}
Account::~Account() {
	//destroys the Account objects
	num_of_basic_accounts--;
}