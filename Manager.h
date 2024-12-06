#pragma once
#include "Account.h"
#include <string>
#include "UserAccount.h"
static int num_of_manager_accounts = 0;
class Manager:public Account
{
	/*
	This class will be very simlar to UserAccount
	it will have different functions like
	add or delete UserAccounts
	perhaps the a manual save and load function should be included in manger class for when
	manager changes, adds, or deletes UserAccounts.

	This class should not need any new data members 
	at least that I can think of 
	*/

	Manager();

	void create_user_account();
	void delete_user_account();
	void view_all_user_data();
	void view_user_data(UserAccount user_account);


	void toString();
	void functions();
	double validate_number(double num);

	void sign_out();

	~Manager();
	
};



