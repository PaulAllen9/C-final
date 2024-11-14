#pragma once
#include <iostream>
using namespace std;
#include <string>


static int num_of_user=0;
static int id_num_user=0;
class User
{
private:
	string user_fname;
	string user_lname;
	string user_id;

public:
	User();
	User(string fname, string lname);

	void setFname(string name);
	string getFname();
	void setLname(string name);
	string getLname();
	string getUserID();
	void toString();

	~User();






};

