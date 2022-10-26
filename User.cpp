#include "User.h"
#include"helper_functions.h"
User::User(const string& user_name, const string& password, const string& type_of_user):user_name(user_name),password(password),type_of_user(type_of_user)
{
	while (check_user() == false)
	{
		cout << "Sorry, username or password is wrong !" << endl;
		cout << "Please,Enter them again : "; cin >> this->user_name; cin >> this->password;
	}
}

void User::add_new_user(const string& user_name, const string& password, const string& user_type)
{
		string file_name = user_type+".txt";
		fstream file_handler(file_name.c_str(), ios::out|ios::app);
		file_handler <<user_name << " " << password << "\n";
		file_handler.close();
		if (user_type == "Customers"); {
			fstream((user_name + ".txt").c_str(), ios::in | ios::out | ios::app).close(); 
		}
}

void User::read_book()const 
{
	if (type_of_user!="Customers") {
		cout << "********* Sorry this is not allowed ! ***********" << endl;
		return;
	}
	string book_name;
	cout << "Please,Enter book name : "; cin >> book_name;
	Book a(book_name);// Programming
	char type;
	cout << "Do you want to read from beginning ? Yes (y) or No (n) :"; cin >> type;
	if (type=='y')
	{
		helper_functions h;
		vector<string>user_history = h.load_file(user_name);
		vector<string>line;
		string his = book_name + " " + to_string(a.view_book(1));
		line.push_back(his);
		h.write_vec_to_new_file(line, user_name);
		//cout << "Succeful operation !" << endl;
		//system("pause");
		h.write_vec_to_file(user_history,user_name);
	}
	else
	{

		int number_of_page =a.set_file(user_name);
		//cout << "history page : " << number_of_page << endl;
		if (number_of_page == 0) {
			update_history (book_name,a.view_book(1));
		}
		else
		{
			helper_functions h;
			vector<string>user_history = h.load_file(user_name);
			vector<string>line;
			string his = book_name + " " + to_string(a.view_book(number_of_page));
			line.push_back(his);
			h.write_vec_to_new_file(line, user_name);
			h.write_vec_to_file(user_history, user_name);
		}
	}
}

void User::update_history(const string & book_name,const int page_number)const
{
	if (type_of_user != "Customers") {
		cout << "********* Sorry this is not allowed ! ***********" << endl;
		return;
	}
	fstream file_handler((user_name + ".txt").c_str(), ios::app);
	file_handler << book_name << " " << page_number << "\n";
	file_handler.close();
}

bool User::check_user() {
	fstream file_handler((type_of_user + ".txt").c_str(), ios::in);
	string line;
	string admin_name;
	string password;
	while (getline(file_handler, line))
	{
		istringstream iss(line);
		iss >> admin_name >> password;
		if (this->user_name == admin_name && this->password == password)
		{
			file_handler.close();
			return true;
		}
	}
	file_handler.close();
	return 0;
}

void User::add_book()const
{
	if (type_of_user == "Customers") {
		cout << "********* Sorry this is not allowed ! ***********" << endl;
		return;
	}
	string book_name;
	int number_of_pages;
	cout << "Please,Enter the book name and the number of total pages:"; cin >> book_name; cin >> number_of_pages;
	Book a(book_name, number_of_pages);
	a.add_book();
}

void User::write_book()const
{
	if (type_of_user == "Customers") {
		cout << "********* Sorry this is not allowed ! ***********" << endl;
		return;
	}
	string book_name;
	int number_of_pages;
	cout << "Please,Enter the book name and the number of total pages:"; cin >> book_name; cin >> number_of_pages;
	Book a(book_name, number_of_pages);
	a.write_book();
}
