#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <chrono>

// std::future<>, std::shared_future<>,

using namespace std;

void my_thread_two_01();
void my_thread_two_02();

void my_threads_two() {
    my_thread_two_01();
    //my_thread_two_02();
}



mutex                   g_mutex_test;
int                     g_id = 0;
const int               g_counter = 100000000;
volatile uint8_t        g_mas[g_counter];

void test_1_01()
{
    for (int i = 0; i < g_counter; i += 2)
    {
        g_mas[i] = 18;
    }
}

void test_1_02()
{
    for (int i = 1; i < g_counter; i += 2)
    {
        g_mas[i] = 18;
    }
}

void test_2_01()
{
    for (int i = 0; i < g_counter / 2; i++)
    {
        g_mas[i] = 19;
    }
}

void test_2_02()
{
    for (int i = g_counter / 2; i < g_counter; i++)
    {
        g_mas[i] = 19;
    }
}

void my_thread_two_01() {

    auto time_start = chrono::high_resolution_clock::now();
    thread thr_1(test_1_01);
    thread thr_2(test_1_02);
    thr_2.join();
    thr_1.join();
    auto time_end_1 = chrono::high_resolution_clock::now();
    auto duration_1 = std::chrono::duration_cast<std::chrono::microseconds>
            ( time_end_1 - time_start ).count();
    for(int i = 0; i < g_counter; i++) {
        if (g_mas[i] != 18)
            cout << "!!!!!! error !!!!!!\n";
    }
    cout << "duration = " << duration_1 << "\n";

    time_end_1 = chrono::high_resolution_clock::now();
    thread thr_11(test_2_01);
    thread thr_21(test_2_02);
    thr_21.join();
    thr_11.join();
    auto time_end_2 = chrono::high_resolution_clock::now();
    auto duration_2 = std::chrono::duration_cast<std::chrono::microseconds>
            ( time_end_2 - time_end_1 ).count();

    for(int i = 0; i < g_counter; i++) {
        if (g_mas[i] != 19)
            cout << "!!!!!! error !!!!!!\n";
    }
    cout << "duration = " << duration_2 << "\n";
}
///////////////////////////////////////////////////////
void my_thread_two_02() {

}
///////////////////////////////////////////////////////

