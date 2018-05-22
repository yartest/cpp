#include <iostream>
#include <vector>
#include <algorithm> // copy()
#include <iterator> // ostream_iterator<int>(cout, ",");
#include <string>

using namespace std;

void test_function_01();

void test_functions() {
	//test_function_01(); // container.cbegin() container.cend()
}

void test_function_01() {
	cout << "\t test_function_01()" << endl;
	vector <int> vec(10);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ":"));
	cout << endl;
	copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, ":"));
	cout << endl;

}
