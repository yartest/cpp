#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>

using namespace std;

// unique_ptr: 'move(ptr)' 'reset()' 'release()' !'get()'
// only unique_ptr can work with arrays
// unique_ptr<Т[]> arr(new Т[2]);
// arr[0].doSomething();
void unique_pointer_functions();
// shared_ptr: count all references; 'make_shared<T>()' 'reset()' 'get()' '='
void shared_pointer_functions();
void weak_pointer_functions();

void pointers_functions() {
	unique_pointer_functions();
	shared_pointer_functions();
	weak_pointer_functions();
}

void unique_pointer_functions() {
	/* unique_ptr<int> x_ptr(new int(3));
	x_ptr = unique_ptr<int>(new int(4));
	unique_ptr<int> y_ptr;
	// compilation error
	//y_ptr = x_ptr;
	// compilation error
	//unique_ptr<int> z_ptr(x_ptr);
	cout << "x_ptr: " << *x_ptr << endl;
	y_ptr = move(x_ptr);
	cout << "y_ptr: " << *y_ptr << endl;
	int *ptr = y_ptr.get();
	*ptr = 7;
	cout << "ptr: " << *ptr << endl;
	cout << "y_ptr: " << *y_ptr << endl;
	ptr = nullptr;
	y_ptr.reset(new int(11));
	cout << "y_ptr: " << *y_ptr << endl;
	ptr = y_ptr.release();
	cout << "ptr: " << *ptr << endl;
	y_ptr.reset(ptr);
	ptr = nullptr;
	cout << "y_ptr: " << *y_ptr << endl; */
}

void shared_pointer_functions() {
	/* shared_ptr<int> ptr = make_shared<int>(8);
	cout << "ptr: " << *ptr << endl; */
}

void weak_pointer_functions() {
	/* shared_ptr<int> ptr = make_shared<int>(7);
	weak_ptr<int> w(ptr);
	if (shared_ptr<int> temp = w.lock()) {
	    cout << "value: " << *temp << endl;
	} */
}
