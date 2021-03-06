#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>

using namespace std;

struct Test {
    Test(int in):data(in)
    {    cout << "Test(in:" << in << ");\n"; }
    ~Test() {    cout << "~Test(in:" << data << ");\n"; }
    Test& operator= (const int &v) { data = v; return *this;}
    int data;
};
std::ostream& operator<<(std::ostream& out, Test& v) {
  out << v.data;
  return out;
}

// unique_ptr: 'move(ptr)' 'reset()' 'release()' !'get()'
// only unique_ptr can work with arrays
// unique_ptr<Т[]> arr(new Т[2]);
// arr[0].doSomething();
void unique_pointer_functions();
// shared_ptr: count all references; 'make_shared<T>()' 'reset()' 'get()' '='
void shared_pointer_functions();
// weak_ptr: 'expired()'
void weak_pointer_functions();

//https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
void pointers_functions() {
    //unique_pointer_functions();
    //shared_pointer_functions();
    //weak_pointer_functions();
}

void unique_pointer_functions() {
    {
        // smart pointer and array
        int n = 10;
        unique_ptr<int[]> array_ptr = make_unique<int[]>(n);
        int *p = array_ptr.get();
        for_each(p, p + n, [](int& element) -> void {
            static int i = 0;
            element = i++;
        });
        for_each(p, p + n, [](const int& element) -> void {
            static int i = 0;
            std::cout << "p[" << i << "] = " << element << "\n";
            i++;
        });
    }


    unique_ptr<Test> x_ptr(new Test(3));
    //Error only from C++14 - make_unique<Test>(33);
    unique_ptr<Test> x_ptr_2 = make_unique<Test>(33);
    x_ptr = unique_ptr<Test>(new Test(4));
    unique_ptr<Test> y_ptr;
    // compilation error
    //y_ptr = x_ptr;
    // compilation error
    //unique_ptr<Test> z_ptr(x_ptr);
    cout << "x_ptr: " << *x_ptr << endl;
    y_ptr = move(x_ptr);
    cout << "y_ptr: " << *y_ptr << endl;
    Test *ptr = y_ptr.get();
    // dont do like following
    //delete ptr;
    *ptr = 7;
    cout << "ptr: " << *ptr << endl;
    cout << "y_ptr: " << *y_ptr << endl;
    ptr = nullptr;
    y_ptr.reset(new Test(11));
    cout << "y_ptr: " << *y_ptr << endl;
    cout << " show address of pointer = 0x" << y_ptr.get() << endl;
    ptr = y_ptr.release();
    cout << " show address of pointer = 0x" << y_ptr.get() << endl;
    cout << "ptr: " << *ptr << endl;
    y_ptr.reset(ptr);
    cout << " show address of pointer = 0x" << y_ptr.get() << endl;
    ptr = nullptr;
    cout << "y_ptr: " << *y_ptr << endl;
    // we cant use unique_ptr with containers
    //vector<unique_ptr<int>> vec;
    //vec.push_back(y_ptr);
    //vector<unique_ptr<int>> vec2(y_ptr, 10);
    unique_ptr<int> test(new int(10));
    cout << *test;
}

void shared_pointer_functions() {
    shared_ptr<Test> ptr = make_shared<Test>(8);
    cout << "ptr: " << *ptr << endl;
    shared_ptr<Test> ptr2(ptr);
    cout << "ptr2: " << *ptr2 << endl;
    cout << "count: " << ptr2.use_count() << endl;
    ptr.reset();
    cout << "ptr count after reset: " << ptr.use_count() << endl;
    cout << "ptr pointer address after reset 0x" << ptr.get() << endl;
    cout << "count: " << ptr2.use_count() << endl;
    ptr = ptr2;
    cout << "count: " << ptr.use_count() << endl;
}

void weak_pointer_functions() {
    shared_ptr<int> ptr = make_shared<int>(77);
    weak_ptr<int> w(ptr);
    if (w.expired()) {
        cout << "weak_ptr is exipred" << endl;
    } else {
        cout << "weak_ptr is NOT exipred" << endl;
    }
    cout << "count: " << w.use_count() << endl;
    if (shared_ptr<int> temp = w.lock()) {
        cout << "count: " << w.use_count() << endl;
        cout << "value: " << *temp << endl;
    }
    ptr.reset();
    cout << "123\n";
    if (shared_ptr<int> temp = w.lock()) {
        cout << "count: " << w.use_count() << endl;
        cout << "value: " << *temp << endl;
    }

    int &&k = 10;
    cout << "k = " << k << "\n";
}
