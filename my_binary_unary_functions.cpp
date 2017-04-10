#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T1> struct my_power2_unary : public unary_function <T1, void>
{
	void operator() (const T1& base) const {
		T1 res(base);
		res *= base;
		cout << base << " ^ 2 = " << res << endl;
	}
};

template <class T1, class T2> struct my_power_binary : public binary_function <T1, T2, void>
{
	void operator() (const T1 &base, const T2 &exp) const {
		T1 res = 1;
		for(T1 i = 1; i <= exp; ++i)
			res *= base;
		cout << base << " ^ " << exp << " = " << res << endl;
	}
};


void my_binary_unary_functions() {
	/*int ary[] = {1, 2, 3, 4, 5};
	vector<int> vec(ary, ary + 5);
	for_each(vec.begin(), vec.end(), my_power2_unary<int>());
	cout << "\n";
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
	for_each(vec.begin(), vec.end(), bind2nd(my_power_binary<int, int>(), 3));
	cout << "\n";*/
}
