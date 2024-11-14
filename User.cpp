#include "User.h"
User::User() {
	/*
	This is the default constructor. 
	It will create a user and use default values for all 
	data members
	*/
	id_num_user++;
	num_of_user++;
	this->user_fname = "none";
	this->user_lname = "none";
	if (id_num_user / 10 == 0) {
		this->user_id = "00"+id_num_user;
	}
	else if (id_num_user / 100 == 0) {
		this->user_id = "0" + id_num_user;
	}
	else if (id_num_user / 1000 == 0) {
		this->user_id = id_num_user;
	}
	else {
		//When user id number is 1000 or greater stop creating users
		cout << "Cannot create user, User memory full" << endl;
	}

}

User::User(string fname, string lname) {
	/*
	This is the name customer constructor.
	It will create a user and use default values for all
	data members except for fname and lname, which will be intialized based of argument
	*/
	id_num_user++;
	num_of_user++;
	this->user_fname = fname;
	this->user_lname = lname;
	if (id_num_user / 10 == 0) {
		this->user_id = "00" + id_num_user;
	}
	else if (id_num_user / 100 == 0) {
		this->user_id = "0" + id_num_user;
	}
	else if (id_num_user / 1000 == 0) {
		this->user_id = id_num_user;
	}
	else {
		//When user id number is 1000 or greater stop creating users
		cout << "Cannot create user, User memory full" << endl;
	}
}

void User::setFname(string name) {
	/*
	This function will...
	set the users first name
	*/
	this->user_fname = name;

}
string User::getFname() {
	/*
	This function will...
	return the users first name
	*/
	return user_fname;
}
void User::setLname(string name) {
	/*
	This function will...
	set user last name
	*/
	this->user_lname = name;

}
string User::getLname() {
	/*
	This function will...
	return user last name
	*/
	return user_lname;
}

string User::getUserID() {
	/*
	This function will...
	return user id
	*/
	return user_id;
}

void User::toString() {
	/*
	This function will...
	display the data of the user
	*/
	std::cout << "Name: " << getFname() << ", " << getLname() << endl;
	std::cout << "Id: " << getUserID() << endl;
}
User::~User() {
	/*
	Deconstructor...
	I dont know what to put here yet
	*/
	
}