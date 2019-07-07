#include <iostream>
#include <string>
#include <vector>

using namespace std;

void my_rvalue_lvalue_01();
void my_rvalue_lvalue_02();

void my_rvalue_lvalue() {
	//my_rvalue_lvalue_01();
	//my_rvalue_lvalue_02();
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
	print_value(99);
	print_value(test);
	print_value(static_cast<int&&>(test));
	print_value(move(test));
	print_value(get_7());

	char t = 'a';
	char & rT = t;
	char && rrChar = '6';
	cout << "sizeof(char) = " << sizeof(t) << endl;
	cout << "sizeof(char&) = " << sizeof(rT) << endl;
	cout << "sizeof(char&&) = " << sizeof(rrChar) << endl;
}

void test_rvalue_function(int&& in) {
	cout << "test_rvalue_function() in:" << in << "\n";
}

template <class T> void test_rvalue_function_template(T&& in) {
	cout << "test_rvalue_function_template() in:" << in << "\n";
}

//forwarding (universal) reference
//https://blog.petrzemek.net/2016/09/17/universal-vs-forwarding-references-in-cpp/
void my_rvalue_lvalue_02() {
	int k = 10;
	test_rvalue_function(10);
	// Error
	//test_rvalue_function(k);
	test_rvalue_function_template<int>(10);
	//Error
	//test_rvalue_function_template<int>(k);
}
