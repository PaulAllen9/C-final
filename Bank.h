#pragma once
#include <string>
#include "Account.h"
class Bank
{
	
private:
	std::string bank_name;
	Account user_list[100];
	Account manager_accounts[5];

public:
	//constructor to build a bank
	Bank(std::string name);
	//starting a day in the bank will consist of loading user and manager data into system for processing
	void start_day();
	//called in start day
	void load_accounts();
	//called in load_accounts
	void load_user_accounts();
	//called in load_accounts
	void load_manager_accounts();
	/*At this point the start page will launch
	this provide options to login as a user or manager, create a user account, or exit the app*/
	void start_page();




	//happens when the user selects the exit option
	//will save data then exit the terminal
	void close_day();
	//called in close_day
	void post_accounts();
	//called in post_accounts
	void post_user_accounts();
	//called in post_accounts
	void post_manager_accounts();

	~Bank();

};

