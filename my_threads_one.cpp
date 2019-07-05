#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <future>
#include <utility>
#include <functional>
#include <deque>

// std::ref(var) - to provide a reference to a thread
// thread.detach(), .join(), .get_id(), .yield(), .sleep_for(),
// .sleep_until(),
// mutex, recursive_mutex, timed_mutex, recursive_timed_mutex
// unique_lock<mutex>
// condition_variable

using namespace std;

mutex					g_mutex;
condition_variable 		g_conditionVariable;
int 					g_data = 0;

//void my_thread_01();
//void my_thread_02();
//void my_thread_03();
//void my_thread_04();
//void my_thread_05();
//void my_thread_06();
//void my_thread_07();
//void my_thread_08();

void my_threads_one() {
	//my_thread_01();
	//my_thread_02();
	//my_thread_03();
	//my_thread_04();
	//my_thread_05();
	//my_thread_06();
	//my_thread_07();
	//my_thread_08();
}
/*
void my_thread_01() {
	auto func = [](const string &first, const string &second) {
		cout << "first:\"" << first << "\" second:\"" << second << "\"" << endl;
	};
	thread thr(func, "Hello", "threads");
	cout << endl << "thread id:" << std::hex << thr.get_id() << endl;
	thr.join();
	cout << "current thread id:" << std::hex << std::this_thread::get_id() << endl;

	//this_thread::sleep_for(chrono::seconds(2));
	//thr.join();
	//thr.detach();
}
*/
/*
///////////////////////////////////////////////////////////////////
void my_construct_data() {
	cout << "my_construct_data() start" << endl;
	this_thread::sleep_for(chrono::seconds(10));
	{
		unique_lock<mutex> lock(g_mutex);
		this_thread::sleep_for(chrono::seconds(10));
		g_data++;
	}
	cout << "my_construct_data() end" << endl;
}

bool isDataReady() {
	cout << "\tisDataReady() start" << endl;
	bool ready = false;
	{
		unique_lock<mutex> lock(g_mutex);
		if (g_data != 0)
			ready = true;
	}
	cout << "\tisDataReady() end" << endl;
	return ready;

}

void my_proccess_data() {

	while (isDataReady() == false)
		this_thread::sleep_for(chrono::seconds(1));

	cout << "my_proccess_data() start" << endl;
	{
		unique_lock<mutex> lock(g_mutex);
		cout << "g_data=" << g_data << endl;
	}
	cout << "my_proccess_data() end" << endl;
}

void my_thread_02() {
	cout << endl << "my_thread_02()" << endl;
	thread createDataThr(my_construct_data);
	thread proccessDataThr(my_proccess_data);
	proccessDataThr.join();
	createDataThr.join();
}
///////////////////////////////////////////////////////////////////
void my_construct_data_02() {
	cout << "my_construct_data_02() start" << endl;
	this_thread::sleep_for(chrono::seconds(10));
	{
		unique_lock<mutex> lock(g_mutex);
		this_thread::sleep_for(chrono::seconds(10));
		g_data++;
	}
	g_conditionVariable.notify_one();
	cout << "my_construct_data_02() end" << endl;
}

void my_proccess_data_02() {
	cout << "my_proccess_data_02() start" << endl;
	{
		unique_lock<mutex> lock(g_mutex);
		g_conditionVariable.wait(lock, [](){ return g_data > 0;});
		cout << "g_data=" << g_data << endl;
	}
	cout << "my_proccess_data_02() end" << endl;
}

// notify_one() CAN NOT run before wait() otherwise deadlock
void my_thread_03() {
	cout << endl << "my_thread_03()" << endl;
	thread createDataThr(my_construct_data_02);
	thread proccessDataThr(my_proccess_data_02);
	proccessDataThr.join();
	createDataThr.join();

}
///////////////////////////////////////////////////////////////////
unsigned factorial(unsigned n) {
	unsigned res = 1;
	for (unsigned i = n; i > 1; --i) {
		res *= i;
	}

	cout << "factorial(): res: " << res << endl;
	return res;
}

void my_thread_04() {
	unsigned x;
	future<unsigned> fu = async(launch::deferred | launch::async, factorial, 4);
	x = fu.get();
	cout << "my_thread_04(): x: " << x << endl;
}
///////////////////////////////////////////////////////////////////
unsigned factorial_02(future<unsigned> &in) {
	unsigned res = 1;
	unsigned n = in.get();
	for (unsigned i = n; i > 1; --i) {
		res *= i;
	}

	cout << "factorial_02(): res: " << res << endl;
	return res;
}

void my_thread_05() {
	unsigned x;
	promise<unsigned> p;
	future<unsigned> fu_p = p.get_future();
	//shared_future<unsigned> shared_f = fu_p.share();

	future<unsigned> fu = async(factorial_02, ref(fu_p));
	this_thread::sleep_for(chrono::seconds(5));
	p.set_value(4);
	x = fu.get();
	cout << "my_thread_05(): x: " << x << endl;
}
///////////////////////////////////////////////////////////////////
class A {
public:
	void f(unsigned x, char c) {}
	void g(unsigned x) {}
	void operator()() {}
};

void foo(int x) {}

void my_thread_06() {
//	A a;
//	thread thr(a, 6);
//	async(launch:async, a, 6);
//	bind(a, 6);
//	call_once(once_flag, a, 6);

	A a;
	thread thr1(a); // copy of a in a different thread
	thr1.join();
	thread thr2(ref(a)); // a in a different thread
	thr2.join();
	thread thr3(A{}); // temp A;
	thr3.join();
	thread thr4([](int x) { return x * x;}, 6);
	thr4.join();
	thread thr5(foo, 6);
	thr5.join();

	thread thr6(&A::f, a, 8, 'w'); // copy of a.f(8, 'w') in a diffrent thread
	thr6.join();
	thread thr7(&A::f, a, 7, 'w'); // a.f(7, 'w') in a diffrent thread
	thr7.join();
	thread thr8(move(a)); // a is no longer usable here
	thr8.join();;

}
///////////////////////////////////////////////////////////////////

deque<packaged_task<unsigned()> > task_deque;

void func() {
	packaged_task<unsigned()> t;
	{
		unique_lock<mutex> lock(g_mutex);
		g_conditionVariable.wait(lock, []() { return !task_deque.empty();});
		t = move(task_deque.front());
		task_deque.pop_front();
	}
	t();
}

unsigned factorial_03(unsigned n) {
	unsigned res = 1;
	for (unsigned i = n; i > 1; --i) {
		res *= i;
	}

	cout << "factorial_03(): res: " << res << endl;
	return res;
}

void my_thread_07() {
	thread thr(func);
	packaged_task<unsigned()> tsk(bind(factorial_03, 4));
	future<unsigned> fu = tsk.get_future();
	{
		lock_guard<mutex> lock(g_mutex);
		task_deque.push_back(move(tsk));
	}
	g_conditionVariable.notify_one();


	thr.join();

	cout << "my_thread_07(): x: " << fu.get() << endl;
}
// there are 3 ways to get a future:
// - promise()::get_future()
// - packaged_task::get_future()
// - async() returns the future
///////////////////////////////////////////////////////////////////
void my_thread_08() {

}
*/
