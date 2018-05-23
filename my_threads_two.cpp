#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <chrono>

// std::ref(var) - to provide a reference to a thread
// thread.detach(), .join(), .get_id(), .yield(), .sleep_for(),
// .sleep_until(),
// mutex, recursive_mutex

using namespace std;

void my_thread_two_01();
void my_thread_two_02();

void my_threads_two() {
	my_thread_two_01();
	my_thread_two_02();
}

void my_thread_two_01() {
	cout << "my_thread_two_01() start" << endl;
	cout << "my_thread_two_01() end" << endl;
}
///////////////////////////////////////////////////////
void my_thread_two_02() {
	cout << "my_thread_two_02() start" << endl;
	cout << "my_thread_two_02() end" << endl;
}
///////////////////////////////////////////////////////

