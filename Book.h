#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Book
{
private:
	string book_name;
	int number_of_pages;
	string list_of_books;
public:
	Book(const string& name);//inizialize book name to load it from database.//for user
	Book(const string& name, const int& number_of_pages);//creating book //for admin
	int check_book();//return number of pages
	void add_book();//add book to my database (from external ,it is only adding its information to my system)
	int set_file(const string& file);//return page that user stoped in
	int view_book(const int &page_number);//printing book to user//for user
	void write_book();// write book in the  database
};

