#pragma once
#include <string>
#include <fstream>
#include "Account.h";
#include "Transaction.h"
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
	static int const transaction_list_size = 100;
	Transaction* transaction_list[transaction_list_size];

	Account* signed_in_user = nullptr;
	Account* signed_in_manager = nullptr;




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
	void load_transactions();


	Account* find_user(int account_number);
	Account* find_manager(int account_number);
	/*At this point all data is loaded and 
	the start page will launch.
	This provide options to login as a user or manager, create a user account, or exit the app*/
	void start_page();

	void sign_in_user();
	
	void sign_in_manager();
	void create_user();
	void delete_user(int account_number);
	void view_all_user_data();
	void view_user_data(int account_number);
	void view_all_manager_data();
	void view_all_transaction_data();
	void view_transaction_data(int account_number);



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

