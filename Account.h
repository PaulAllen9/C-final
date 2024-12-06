#pragma once
#include <string>
#include <iostream>
static int num_of_basic_accounts = 0;
static int numb_for_account_num = 0;
//both the user and manager accounts will inherit from this class
class Account
{
private:
	
	int account_number;
	std::string fname;
	std::string lname;
	std::string password;
	std::string account_type = "Basic_Account";

public:
	//I think we need to use pure virtualism here and virtualism
	//Also might have to make another constructor for when we read from a file
	Account();
	virtual void toString();

	
	virtual void functions();


	int get_account_number();
	void setFname(std::string name);
	std::string getFname();
	void setLname(std::string name);
	std::string getLname();
	void set_account_type(std::string type);
	std::string get_account_type();

	//we will never sign in as a normal account, so we will never need to sign out
	//therefor we do not need to define the function in basic account
	virtual void sign_out()=0;

	~Account();

};

