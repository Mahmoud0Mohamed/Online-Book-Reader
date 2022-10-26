#include "helper_functions.h"
void helper_functions::write_vec_to_new_file(const vector<string>& lines, const string& file_name) {

	string path = file_name + ".txt";
	fstream file_handler(path.c_str(), ios::trunc);
	file_handler.close();

	fstream file_handler2(path.c_str(), ios::out);
	int size = lines.size();
	for (int i = 0; i < size; i++)
	{
		file_handler2 << lines[i] << "\n";
	}
	file_handler2.close();
}

vector<string>helper_functions::load_file(const string& file_name) {
	string path = file_name + ".txt";

	fstream file_handler(path.c_str(), ios::in | ios::out | ios::app);

	string line;

	vector<string>lines;
	
	while (getline(file_handler, line))
	{
		lines.push_back(line);
	}
	return lines;
}

void helper_functions:: write_vec_to_file(const vector<string>& lines, const string& file_name) {
	string path = file_name + ".txt";
	
	fstream file_handler2(path.c_str(), ios::app);
	int size = lines.size();
	for (int i = 0; i < size; i++)
	{
		file_handler2 << lines[i] << "\n";
	}
	file_handler2.close();

}