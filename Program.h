#pragma once
#include "User.h"
class Program
{
private:
	User* user = nullptr;
public:
	Program();
	Program(const Program &p);
	void signup(const char& type_of_user)const;
	void login(const char& type_of_user);
	~Program();
};

