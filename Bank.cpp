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

}
//called in load_accounts
void Bank::load_manager_accounts() {

}
/*At this point the start page will launch
this provide options to login as a user or manager, create a user account, or exit the app*/
void Bank::start_page() {
	//generates prompt to sign in, create an account or exit
	//please enter u to sign in as user
	//please enter c to create an account
	//please enter m to sign in as manager
	//please enter e to exit


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