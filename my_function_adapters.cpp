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

void my_functor_adapters_01(); //ptr_fun() mem_fun() mem_fun_ref()
void my_functor_adapters_02(); //mem_fn()

void my_functor_adapters() {
	//my_functor_adapters_01();
	//my_functor_adapters_02();
}

void my_functor_adapters_01() {
	vector<Element> vec(2);			// size == 2
	vector<Element*> vecPointers;	// size == 1
	vecPointers.push_back(&vec[0]);
	//mem_fun_ref()
	for_each(vec.begin(), vec.end(), mem_fun_ref(&Element::print));
	cout << "a\n";
	//mem_fun()
	for_each(vecPointers.begin(), vecPointers.end(),
						mem_fun(&Element::print));
	cout << "b\n";
	for_each(vec.begin(), vec.end(), my_print_ref);
	cout << "c\n";
	//ptr_fun
	for_each(vecPointers.begin(), vecPointers.end(), ptr_fun(my_print));
	for_each(vecPointers.begin(), vecPointers.end(), my_print);

}

struct Test {
    void hello_world() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};

void my_functor_adapters_02() {
	Test t;
	auto hello = mem_fn(&Test::hello_world);
	hello(t);

    auto print_num = mem_fn(&Test::display_number);
    print_num(t, 42);

    auto access_data = mem_fn(&Test::data);
    std::cout << "data: " << access_data(t) << '\n';
    access_data(t) = 10;
    std::cout << "data: " << access_data(t) << '\n';
}
