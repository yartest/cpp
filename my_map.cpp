#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

void map_constructors();
void map_lower_bound_upper_bound_equal_range();

// map::count(key) returns 0 or 1
// map::insert do nothing if already exist

void map_functions() {
	map_constructors();
	map_lower_bound_upper_bound_equal_range();
}

void map_constructors() {
	//typedef map<int, char, less<int> > M;
	using M = map<int, char>;
	M m1;
	m1.insert(make_pair(2,'B'));
	m1.insert(M::value_type(3,'C'));
	m1.insert(pair<int, char>(1,'A'));
	M::iterator It = m1.begin();
	cout << "m1:" << endl;
	for (const auto &element: m1) {
		cout << element.first << " - " << element.second << endl;
	}
    M m2(m1);
    cout << "m2:" << endl;
	for (const auto &element: m2) {
		cout << element.first << " - " << element.second << endl;
	}
    M m3(m2.begin(),m2.end());
    cout << "m3:" << endl;
	for (const auto &element: m3) {
		cout << element.first << " - " << element.second << endl;
	}
}

void map_lower_bound_upper_bound_equal_range() {
	using M = map<int, char>;
	M m1;
	m1[2] = 'B'; m1[1] = 'A'; m1[3] = 'C';
	m1[11] = 'X'; m1[12] = 'Y'; m1[13] = 'Z';
	cout << "m1:" << endl;
	for (const auto &element: m1) {
		cout << element.first << " - " << element.second << ":";
	}
	cout << endl;
	cout << "2:" << endl;

	auto It = m1.lower_bound(2);  // itlow points to 2
	cout << (*It).first << " - " << (*It).second << endl;
	It = m1.upper_bound(2);   // itup points to 3
	cout << (*It).first << " - " << (*It).second << endl;
	It = m1.equal_range(12).first;
	cout << (*It).first << " - " << (*It).second << endl;
	It = m1.equal_range(12).second;
	cout << (*It).first << " - " << (*It).second << endl;
}

