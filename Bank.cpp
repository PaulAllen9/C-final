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

}
//called in load_accounts
void Bank::load_manager_accounts() {
	//some how load manager accounts from txt file

}
/*At this point the start page will launch
this provide options to login as a user or manager, create a user account, or exit the app*/
void Bank::start_page() {
	//will server as the hub for user interaction with the bank applicaiton
	//will still need to add formatting to make the app look presentable
	std::cout << "Welcome to the our bank, " << bank_name <<"!" << std::endl;
	std::cout << "Functions:" << "Type to enact " << bank_name << std::endl;

	std::cout << "To sign-in as user: " << "User" << std::endl;
	std::cout << "To create a user account: " << "Create" << std::endl;
	std::cout << "To sign-in as manager: " << "Manage" << std::endl;
	std::cout << "To exit the applicaiton: " << "Exit" << std::endl;
	std::string task1;
	std::cin >> task1;


	//sign-in either
	//please enter account number...
	//please enter account password...
	//check adn validate info to sign-in
		//valid data
		//load their functions prompt
		// 
		//invalid data
		//ask them to try again

	//create an account
	//create user
		//please enter first name
		//please enter last name
	//auto provide account number (based off number of already existing accounts)
	//auto provide account type("user")
	//please enter the password you would like to use for your account
	//pleae enter the starting balance for you account(assume they are able only enter positive number)

	//exit call close_day()

}

void Bank::sign_in_user()
{
}

void Bank::create_user()
{
}

void Bank::sign_in_manager()
{
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