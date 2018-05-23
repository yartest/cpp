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

mutex					m_data;
condition_variable 		check_data;
int 					g_data = 0;

void my_thread_01();
void my_thread_02();

void my_construct_data();
void my_proccess_data();

void my_threads_one() {
	my_thread_01();
	my_thread_02();
}

void my_thread_01() {
	auto func = [](const string &first, const string &second) {
		cout << "first:\"" << first << "\" second:\"" << second << "\"" << endl;
	};
	thread thr(func, "Hello", "threads");
	cout << endl << "thread id:" << std::hex << thr.get_id() << endl;
	thr.join();
	cout << "current thread id:" << std::hex << std::this_thread::get_id() << endl;
}
///////////////////////////////////////////////////////
void my_thread_02() {
	cout << endl << "my_thread_02()" << endl;
	thread createDataThr(my_construct_data);
	thread proccessDataThr(my_proccess_data);
	proccessDataThr.join();
	createDataThr.join();
}

void my_construct_data() {
	cout << "my_construct_data() start" << endl;
	this_thread::sleep_for(chrono::seconds(10));

	m_data.lock();
	this_thread::sleep_for(chrono::seconds(10));
	g_data++;
	m_data.unlock();

	cout << "my_construct_data() end" << endl;
}

bool isDataReady() {
	cout << "\tisDataReady() start" << endl;
	bool ready = false;

	m_data.lock();
	if (g_data != 0)
		ready = true;
	m_data.unlock();

	cout << "\tisDataReady() end" << endl;
	return ready;

}

void my_proccess_data() {

	while (isDataReady() == false)
		this_thread::sleep_for(chrono::seconds(1));

	cout << "my_proccess_data() start" << endl;
	m_data.lock();
	cout << "g_data=" << g_data << endl;
	m_data.unlock();
	cout << "my_proccess_data() end" << endl;
}
///////////////////////////////////////////////////////

