#include "Bank.h"
//constructor to build a bank
Bank::Bank(std::string name) {

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


}
//called in load_accounts
void Bank::load_user_accounts() {
	//some how load user accounts from txt file
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string line;
	inputFile.open("user.txt");
	while (!inputFile.eof()) {
		getline(inputFile, line);
		//account_num,password,UserfName,UserlName,balance
		//create user account with that data
			//create tempstring to store data from line.
			//split the string by commas
			//call user account constructor with the data
		//load data into user_list
	}
	inputFile.close();
}
//called in load_accounts
void Bank::load_manager_accounts() {
	//similar to function above
}

void Bank:: find_user(int account_number) {
	for (int i = 0; i < user_list_size; i++) {
		
	}
}




/*At this point the start page will launch
this provide options to login as a user or manager, create a user account, or exit the app*/
void Bank::start_page() {
	//will serve as the hub for user interaction with the bank applicaiton
	//will still need to add formatting to make the app look presentable
	std::cout << "Welcome to our bank, " << bank_name <<"!" << std::endl;
	std::cout << "Functions:" << "Type to enact " << std::endl;

	std::cout << "To sign-in as user: " << "User" << std::endl;
	std::cout << "To create a user account: " << "Create" << std::endl;
	std::cout << "To sign-in as manager: " << "Manager" << std::endl;
	std::cout << "To exit the applicaiton: " << "Exit" << std::endl;
	std::string task1;
	std::cin >> task1;

	if (task1 == "User" or task1 == "user") {
		sign_in_user();
	}
	else if (task1 == "Create" or task1 == "create") {
		create_user();
	}
	else if (task1 == "Manager" or task1 == "manager") {
		sign_in_manager();
	}
	else if (task1 == "Exit" or task1 == "exit") {
		exit();
	}
	else {
		std::cout << "You entered " << task1 << ",which is not a proper response. Returning to start..." << std::endl;
		start_page();
	}
	

	
	
}

void Bank::sign_in_user()
{
	//crete prompt to sign in with account number and password
	//read values from user.txt
		//compare sign-in values to known accounts
		//success = print functions
		//implementing functions
			//probably create a temp user account and load in the data from the txt file
			//do user functions on that temp account
		//fail = print notice failed to sign-in return to start_page
}

void Bank::create_user()
{
	//create prompt to make account
	//create user and add to user.txt - joseph will do
	//accounts will be in the form account number(primary key, auto incrementing), first name, last name, balance
	//transactions will be stored in a seperate file 
	//probably in the form account number, starting balance, transaction type(deposit, withdrawl, ect.), amount, end balance
	//I'm thinking we proably could tag the transaction log onto the user data in the user.txt but will leave decision up to who ever codes it
	
	//return to start page to sign-in
	start_page();
}

void Bank::sign_in_manager()
{
	//crete prompt to sign in
	//read values from manager.txt
		//compare sign-in values to known accounts
		//success = print functions
		//implementing functions
			//probably create a temp manager account and load in the data from the txt file
			//do manager functions on that temp account
		//fail = print notice failed to sign-in return to start_page
}

void Bank::exit()
{
	close_day();
	std::cout << "Thank you for using " << bank_name<<"," << std::endl;
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
	/*puts user information into the txt file*/

}
//called in post_accounts
void Bank::post_manager_accounts() {
	/*puts manager information into the txt file*/
}

Bank::~Bank() {

}