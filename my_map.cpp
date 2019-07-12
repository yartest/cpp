#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>


using namespace std;

void map_constructors();
void map_lower_bound_upper_bound_equal_range();
void map_functions_03();

// map::count(key) returns 0 or 1
// map::insert do nothing if already exist


// хеш таблиці - unordered_map https://codeforces.com/blog/entry/4710
void map_functions() {
	//map_constructors();
	//map_lower_bound_upper_bound_equal_range();
	map_functions_03();
}

void map_constructors() {
	//typedef map<int, char, less<int> > M;
	using M = map<int, char>;
	M m1;
	m1.insert(make_pair(2,'B'));
	m1.insert(M::value_type(3,'C'));
	m1.insert(pair<int, char>(1,'A'));
	M::iterator It = begin(m1);

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

	using UM = unordered_map<int, char>;
	UM um1(m1.begin(), m1.end());
    cout << "um1:" << endl;
	for (const auto &element: um1) {
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
		cout << element.first << "-" << element.second << ":::";
	}
	cout << endl;
	cout << "2:" << endl;

	auto It = m1.lower_bound(2);  // itlow points to 2
	cout << (*It).first << " - " << (*It).second << endl;
	It = m1.upper_bound(2);   // itup points to 3
	cout << (*It).first << " - " << (*It).second << endl;
	cout << "12:" << endl;
	It = m1.equal_range(12).first;
	cout << (*It).first << " - " << (*It).second << endl;
	It = m1.equal_range(12).second;
	cout << (*It).first << " - " << (*It).second << endl;
}

//http://codeforces.com/blog/entry/21853
// Error:
// unordered_map<pair<int,int>,int>mp;
// You will get Compilation Error! Why? See this page (http://www.cplusplus.com/reference/functional/hash/)
// for unordered_map supported types. For unsupported types, you have to create
// your own hash function and operator == for use

class Test {};

struct Node {
	int a;
	int b;
	Node(int in_a, int in_b) :a(in_a), b(in_b) {}
};

void map_functions_03()
{
	// Error:
	//unordered_map<Test, int> mp01;

	map <Test, int> mp02;
	Test test;
	// Error:
	// mp02[test] = 2;

	using h = std::hash<int>;
	auto hash = [](const Node& n){return h()(n.a) * h()(n.b);};
	auto equal = [](const Node& l, const Node& r){return l.a == r.a && l.b == r.b;};
	// 8 - Minimal initial number of buckets
	std::unordered_map<Node, int, decltype(hash), decltype(equal)> m(8, hash, equal);
	m.insert(make_pair(Node(1, 2), 3));
	m.insert({Node(4, 5), 6});
	m.insert(pair<Node, int>(Node(7, 8), 9));

	cout << "Node(4, 5) = " << m[Node(4, 5)] << "\n";
}

