#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

//

void my_common_set_functions();

void set_functions() {
	my_common_set_functions();
}

void my_common_set_functions() {
	unordered_set<int> data_set = {1, 3, 5, 7, 10};

	copy(data_set.cbegin(), data_set.cend(), ostream_iterator<int>(cout, ":"));
	cout << endl;
	for(const auto &element : data_set) {
		cout << element << "-";
	}
	cout << endl;

	cout << "load factor: " << data_set.load_factor() << endl;
	int x = 10;
	cout << "load factor: " << data_set.bucket(10) << endl;
	cout << "load factor: " << data_set.bucket_count() << endl;
}
