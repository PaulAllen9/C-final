#pragma once
#include <string>
#include "User.h"
class Transaction
{
private:
	User user;
public:
	//constructor with action a
	Transaction(int a);





	void withdrawl();
	void deposit();
};

