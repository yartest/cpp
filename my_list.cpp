#include <iostream>
#include <list>
#include <string>
#include <algorithm> // copy()
#include <iterator> // ostream_iterator

using namespace std;

void list_sort_unique();
void list_remove_01();

void list_functions() {
	//list_sort_unique();
	//list_remove_01();
}

void list_sort_unique() {
	int ary[] = {4, 1, 1, 2, 5, 3, 2, 4, 3, 5};
    list<int> li(ary, ary + 10);
	copy(begin(li), end(li), ostream_iterator<int>(cout, " "));
	cout << endl;
	li.sort();
	//li.sort(less<int>());
	//li.sort(greater<int>());
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	li.sort(greater<int>());
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	li.unique(); // only for already sorted list
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void list_remove_01() {
	int arr[]= {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	int remove_element = 3;
	list<int> lst(arr, arr + 15);
	copy(lst.begin(), lst.end(), ostream_iterator<int>(cout,","));
	cout << endl;
	lst.remove(remove_element);
	cout << "list:" << endl;
	copy(lst.begin(), lst.end(), ostream_iterator<int>(cout,","));
	cout << endl;
}
