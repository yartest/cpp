#include <iostream>

using namespace std;

void initializer_list_01();

void my_initializer_list() {
	//initializer_list_01();
}

// https://habr.com/ru/post/330402/
void initializer_list_01() {

	// initializer_list<int> type of y
	auto y = {1, 2};

	const int k = 10;
	cout << "k=" << k << "\n";
	//static_assert(k <= 0, "k greater than 0, error");


}
