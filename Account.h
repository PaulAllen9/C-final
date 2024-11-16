#pragma once
#include "User.h"
#include <string>

static int number_of_accounts = 0;
//both the user and manager accounts will inherit from this class
class Account
{
private:
	
	int account_number;
	string fname;
	string lname;
	std::string password;
	std::string account_type;

public:
	//I think we need to use pure virtualism here and virtualism
	Account();
	void toString();

	void functions();
	void setFname(string name);
	string getFname();
	void setLname(string name);
	string getLname();

	
	void sign_out();

	~Account();

};

