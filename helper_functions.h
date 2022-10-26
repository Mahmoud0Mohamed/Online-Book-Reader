#pragma once
#include <string>
#include<fstream>
#include<vector>
using namespace std;
class helper_functions
{
public:
	void write_vec_to_new_file(const vector<string>& lines, const string& file_name);
	void write_vec_to_file(const vector<string>& lines, const string& file_name);
	
	vector<string>load_file(const string& file_name);
};

