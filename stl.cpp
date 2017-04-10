#include <iostream>

using namespace std;

void input_output_data();
void input_output_data_c();
void string_functions();
void vector_functions();
void list_functions();
void map_functions();
void my_binary_unary_functions();
void pointers_functions();
void lambda_functions();

// C11 https://habrahabr.ru/post/182920/
// C11 lambda https://habrahabr.ru/post/66021/
// algorithms http://www.cplusplus.com/reference/algorithm/
// Eclipse enable C11 http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-luna-cdt
// only string has internal function 'find' 'at(i)' '[i]'
// vector has 'at(i)' '[i]'
// list has 'merge' 'remove' 'reverse' 'sort' 'splice'
// map has 'find' 'count' '[key]' 'upper_bound' 'lower_bound' 'equal_range' 'key_comp' 'value_comp'

//int main(int argc, char *argv[])
int main()
{
	try {
		input_output_data();
		input_output_data_c();
		string_functions();
		vector_functions();
		list_functions();
		map_functions();
		my_binary_unary_functions();
		pointers_functions();
		lambda_functions();
		string str("some description.");
		throw str;
	}
	catch (string &info) {
		cout << "main(): an exception: " << info << endl;
	}
	catch (...) {
		cout << "main(): an exception has been caught." << endl;
	}
	cout << "main(): the end of the main().\n";
	return 0;
}
