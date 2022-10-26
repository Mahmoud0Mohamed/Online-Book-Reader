#include "Book.h"
#include"helper_functions.h"

Book::Book(const string& name, const int& number_of_pages) :book_name(name), number_of_pages(number_of_pages), list_of_books("list_of_books") {}//creating //for admin

Book::Book(const string &name): book_name(name),number_of_pages(0), list_of_books("list_of_books")//reading //for user
{
	int number_of_pages = check_book();
	while (number_of_pages==0)
	{
		cout << "Sorry,there is no book with this name." << endl;
		cout << "Enter name again please :";cin >> book_name;
	}
	this->number_of_pages = number_of_pages;
}

int Book:: check_book()  {
	fstream file_handler((list_of_books + ".txt").c_str(), ios::in);
	string line;
	string book_name;
	int number_of_pages;
	while (getline(file_handler, line))
	{
		istringstream iss(line);
		iss >> book_name >> number_of_pages;
		//cout << "the book name is : " << book_name << "   " << "number of pages is : " << number_of_pages << endl;
		if (this->book_name==book_name)
		{
			file_handler.close();
			return number_of_pages;
		}
	}
	file_handler.close();
	return 0;
}

int Book::set_file(const string &file) {
	//data member
	this->list_of_books = file;
	int number = check_book();
	//cout << "i am set file and the number is : " << number << endl;
	list_of_books = "list_of_books";// i reset it 
	return number;
}

int Book::view_book(const int &page_number) {
	cout << "number of pages:" << number_of_pages << endl;
	int current_page = page_number;
	helper_functions o1;
	vector<string>lines = o1.load_file(book_name);
	int size = lines.size();
	//cout << "number of lines: " << size << endl;
	char line;
	while (true)
	{
		for (int i = (current_page - 1) * 10; ((i < size) && (i < (current_page * 10))); i++)
		{
			cout << lines[i] << endl;
			cout << endl;
		}
		cout << "\t" << "page number :" << current_page << endl;
		cout << endl;
		cout << "Previous (-)" << "\t"<<"\t"<<"END(neither)" << "\t" << "\t" << "Next (+)" << endl;
		cout << "Enter your Choice :"; cin >> line;
		if (line=='+')
		{
			current_page++;
		}
		else if(line=='-'){
			current_page--;
		}
		else
		{
			return current_page;
		}
		if (current_page>number_of_pages)
		{

			cout << "Sorry,it the end of the book" << endl;
			return --current_page;
		}
	}
}

void Book::add_book() {
	fstream file_handler((list_of_books + ".txt").c_str(), ios::out | ios::in | ios::app);
	file_handler << book_name << " " << number_of_pages << "\n";
	file_handler.close();
}

void Book::write_book(){
	fstream file_handler((list_of_books + ".txt").c_str(), ios::out | ios::in | ios::app);
	file_handler << book_name << " " << number_of_pages << "\n";
	file_handler.close();
	fstream file_handler2((book_name + ".txt").c_str(), ios::out | ios::app);
	string line = "a";
	cout << "Enter -1 when you finish -_- :" << endl;
	cin.ignore();
	while (true)
	{

		cout << "The line :";
		getline(cin, line);
		if (line != "-1")
		{
			file_handler2 << "\t" << "\t" << line << "\n";
		}
		else
		{
			break;
		}
	}
	file_handler2.close();
}
