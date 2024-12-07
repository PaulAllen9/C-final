#pragma once
#include <string>
#include <fstream>
#include "Account.h";
class Bank
{
	
private:
	std::string bank_name;
	//arrays of User account pointers thinking 20 or so
	static int const user_list_size = 20;
	Account* user_list[user_list_size];
	//arrays of Manager account pointers thinking around 5, one for each of us then maybe some for testing
	static int const manager_list_size = 5;
	Account* manager_accounts[manager_list_size];

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

	void find_user(int account_number);
	/*At this point all data is loaded and 
	the start page will launch.
	This provide options to login as a user or manager, create a user account, or exit the app*/
	void start_page();

	void sign_in_user();
	void create_user();
	void sign_in_manager();
	void exit();




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

