#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include"Book.h"
using namespace std;

class User
{
private:
	string user_name;
	string password;
	string type_of_user;//admin or customer
public:
	User(const string& user_name, const string& password,const string& type_of_user);
	static void add_new_user(const string& user_name, const string& password,const string &user_type);
	void read_book()const;
	void update_history(const string& book_name, const int page_number)const;
	bool check_user();
	void add_book()const;
	void write_book()const;
};

