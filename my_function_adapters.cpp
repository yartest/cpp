#include <iostream>
#include <vector>
#include <algorithm> // copy()
#include <functional>

using namespace std;

class Element;

void my_print(Element *in) {
	in;
	static int counter = 0;
	counter++;
	cout << "counter: " << counter << endl;
}

void my_print_ref(Element &in) {
	my_print(&in);
}

class Element {
public:
	void print() {
		my_print(this);
	}
};

void my_functor_adapters_01(); //ptr_fun mem_fun mem_fun_ref

void my_functor_adapters() {
	//my_functor_adapters_01();
}

void my_functor_adapters_01() {
	vector<Element> vec(2);			// size == 2
	vector<Element*> vecPointers;	// size == 1
	vecPointers.push_back(&vec[0]);
	for_each(vec.begin(), vec.end(), mem_fun_ref(&Element::print));
	for_each(vecPointers.begin(), vecPointers.end(),
						mem_fun(&Element::print));
	for_each(vec.begin(), vec.end(), my_print_ref);
	for_each(vecPointers.begin(), vecPointers.end(), ptr_fun(my_print));

}
