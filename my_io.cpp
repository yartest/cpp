#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void input_output_string();
void input_output_file();

void input_output_data() {
	//input_output_string();
	//input_output_file();
}

void input_output_string() {
	string s_a, s_b;
	cout << "Input s_a ";
	getline(cin, s_a);
	cout << "Input s_b ";
	getline(cin, s_b);
	cout << "a + b = " << s_a << s_b << endl;
}

void input_output_file() {
	string file_name("/home/test/workspace/test_file.dat");
	ofstream ofile_test(file_name);
	//ofstream ofile_test(file_name.c_str());
	if (!ofile_test.is_open()) {
		cout << "the output file is closed\n";
		return;
	}
	string str_test("10;32;44; 87;\n10;23;45\n");
	ofile_test << "123;\n";
	ofile_test << str_test;
	ofile_test.close();

	ifstream ifile_test(file_name.c_str());
	if (!ifile_test.is_open()) {
		cout << "the input file is closed\n";
		return;
	}
	string str_output((istreambuf_iterator<char>(ifile_test)), (istreambuf_iterator<char>()));
	cout << "Begin" << endl;
	cout << str_output;
	cout << "End" << endl << endl;

	ifile_test.clear();
	ifile_test.seekg(0, ios::beg);
	while (!ifile_test.eof()) {
		getline(ifile_test, str_output);
		if (!str_output.empty())
			cout << str_output << endl;
	}
}
