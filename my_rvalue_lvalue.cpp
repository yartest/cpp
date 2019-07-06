#include <iostream>
#include <string>
#include <vector>

using namespace std;

void my_rvalue_lvalue_01();

void my_rvalue_lvalue() {
	my_rvalue_lvalue_01();
}

void print_value(int &in) {
	cout << "L-value in:" << in << "\n";
}

void print_value(int &&in) {
	cout << "R-value in:" << in << "\n";
}

int get_7() { return 7; }

void my_rvalue_lvalue_01() {
	int &&test = 10;
	cout << "test:" << test << "\n";
	print_value(test);
	print_value(get_7());
}
