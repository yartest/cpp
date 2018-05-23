#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // copy()
#include <iterator> // ostream_iterator

using namespace std;

// std::array - its size is fixed at compile time and
// it will be allocated as a single chunk (e.g. taking space
// on the stack)
// - кількість елементів відома перед компіляцією,
// - память для елементів виділяється на стеку
// цими двома пунктами він відрізняється від вектора



// resize, size; reserve, capacity;
void vector_constructors();
void vector_assign_at_back_clear_empty();
void vector_erase_push_back_insert();
void vector_remove_erase();

void vector_functions() {
	//vector_constructors();
	//vector_assign_at_back_clear_empty();
	//vector_erase_push_back_insert();
	//vector_remove_erase();
}

void vector_constructors() {
	string str[]= {"Alex", "John", "Robert"};
	vector<int> v1;
	vector<int> v2(10); // 10 elements
    vector<int> v3(10, 0); // 10 elements with value 0
    vector<string> v4(str + 0, str + 3);
    vector<string>::iterator sIt = v4.begin();
    while (sIt != v4.end())
        cout << *sIt++ << " ";
    cout << endl;
    vector<string> v5(v4);
    for (size_t i = 0; i < v5.size(); i++) {
        cout << v5[i] << " ";
        cout << v5.at(i) << " ";
    }
    cout << endl;
}

void vector_assign_at_back_clear_empty() {
	int ary[]= {1, 2, 3, 4, 5};
	vector<int> v;
	v.assign(ary, ary + 5);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    v.assign(3, 100); // 3 elements with value 100
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl << endl;

	v[0] = 300;
	v.at(1) = 400;
	for (int i = 0; i < 3; i++)
    	cout << v.at(i) << " ";
	cout << endl;
	cout << "the last element: " << v.back() << endl;
	cout << "the first element: " << v.front() << endl;
	v.clear();
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	if (v.empty())
		cout << "v is empty." << endl;
}

void vector_erase_push_back_insert() {
	int ary[]= {1, 2, 3, 4, 5};
	vector<int> v;
	v.assign(ary, ary + 5);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	v.erase(v.begin(), v.begin() + 3);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	v.insert(v.begin(), 1);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	v.insert(v.begin() + 1, ary + 1, ary + 3);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	v.push_back(6);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	v.pop_back();
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl << endl;
}

void vector_remove_erase() {
	int arr[]= {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	vector<int> vec(arr, arr + 15);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout,","));
	cout << endl;

	int remove_element = 2;
	vec.erase(remove(vec.begin(), vec.end(), remove_element), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout,","));
	cout << endl;

	//for list container
	//list.remove(value);
	remove_element = 3;
	list<int> lst(arr, arr + 15);
	lst.remove(remove_element);
	cout << "list:" << endl;
	copy(lst.begin(), lst.end(), ostream_iterator<int>(cout,","));
	cout << endl;
}
