#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;
/*
[]                      // no capture list
[=]                     // all variables by value
[&]                     // all variables by reference
[in, &out]              // in variable by value, out variable by reference
[=, &out1, &out2]       // all variables by value except out1 and out2 by reference
[&, x, &y]              // all variables by reference except x by value
*/
template <typename T, size_t R, size_t C> void two_d_array(T (&array)[R][C])
{
	for(size_t i = 0; i < R; i++)
		for (size_t j = 0; j < C; j++)
			array[i][j] = (T)(i + j);
}

void lambda_functions() {
	/* cout << "GCC version: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__
        << "\nVersion string: " << __VERSION__ << endl;

	int ary[] = {1, 2, 3, 4, 5};
	list<int> lst(ary, ary + 5);
	for_each(begin(lst), end(lst), [](int element){ cout << element << ":";});
	cout << endl;
	for_each(lst.begin(), lst.end(), [](int element){ cout << element << ":";});
	cout << endl;

	auto is_odd = [](int n) -> bool {return n % 2 == 1;};

	auto lambdaChange = [] (int val) -> function<int (int)> {
		return [val] (int nnn) -> int { return val + nnn;};
	};

	list<int> result;
	transform(begin(lst), end(lst), back_inserter(result), lambdaChange(2));

	for_each(begin(result), end(result), [](int element){ cout << element << ":";});
	cout << endl;
	for(auto element: result)
		cout << element << "-";
	cout << endl;


	cout << "------------2D ARRAY---------------------------\n";
	const int mR = 3;
	const int mC = 3;
	int mas[mR][mC];
	//two_d_array<int, mR, mC>(mas);
	two_d_array(mas);
	copy(&mas[0][0], &mas[0][0] + mR * mC, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "------------2D ARRAY END---------------------------\n"; */
}
