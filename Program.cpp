#include "Program.h"
//interface
Program::Program():user(nullptr) {
{
		cout << "\t" << "Hello to online Book store" << endl;
		while (true)
		{
			cout << "\t" << "1- Sign_Up." << endl;
			cout << "\t" << "2- Log__in." << endl;
			cout << "Enter from 1 - 2:" << endl;
			int choice = 0;
			cout << "Please,Enter your choice here : "; cin >> choice;

			cout << "Sir,Are you Customer (c) or Admin(a) ?" << endl;
			char type_of_user;
			cout << "Please, Enter your answer here: "; cin >> type_of_user;
			if (choice == 1 && (type_of_user == 'a' || type_of_user == 'c'))
			{
				signup(type_of_user);
				break;
			}
			else if (choice == 2 && (type_of_user == 'a' || type_of_user == 'c')) {
				login(type_of_user);
				break;
			}
			else
			{
				cout << "Sorry there is wrong in your input" << endl;
				cout << "Please, Enter them again -_- " << endl;
			}
		}
	}
}
//copy instructor to avoid shallow copy
Program::Program(const Program& p)
{
	if (this->user==nullptr)
	{
		this->user = new User("mahmoud", "1234", "Admins");
		*user = *p.user;
	}
	else
	{
		delete user;
		this->user = new User("mahmoud", "1234", "Admins");
		*user = *p.user;
	}
}

void Program::signup(const char& type_of_user)const
{
	{
		string username;
		string password;
		cout << "Please Sir,Enter your username and password !" << endl;
		cout << "Here :"; cin >> username >> password;
		if (type_of_user == 'a')
		{
			User::add_new_user(username, password, "Admins");
		}
		else {
			User::add_new_user(username, password, "Customers");
		}
	}
}

void Program::login(const char& type_of_user)
{
	{
		string username;
		string password;
		cout << "Please Sir,Enter your username and password !" << endl;
		cout << "Here :"; cin >> username >> password;
		if (type_of_user == 'a')
		{
			user = new User(username, password, "Admins");
			cout << "Menu:" << endl;
			cout << "\t" << "1- Add Book." << endl;
			cout << "\t" << "2- Write Book." << endl;
			while (true)
			{
				int num = 0;
				cout << "Enter number from range 1 - 2: "; cin >> num;
				if (num == 1) {
					user->add_book();
					break;
				}
				else if (num == 2) {
					user->write_book();
					break;
				}
				else
				{
					cout << "Wrong number try again! -_-" << endl;
				}
			}
		}
		else {
			user = new User(username, password, "Customers");
			user->read_book();
		}

	}
}

Program::~Program()
{
	if (user != nullptr)
	{
		delete user;
		user = nullptr;
	}
	cout << "\t" << "\t" << "Good Bye ,Sir" << endl;
}










