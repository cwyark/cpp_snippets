#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

mutex g_mutex;

void threadFunc(void) {
    lock_guard<mutex> lock(g_mutex);
    cout << this_thread::get_id() << endl;
    auto ts_1 = chrono::system_clock::now();
    this_thread::sleep_for(chrono::duration<int, milli>(1000));
    auto ts_2 = chrono::system_clock::now();
    auto deltaTs = ts_2 - ts_1;
    cout << "Time Delta is: " << deltaTs.count() << endl;
}

int main(void) {
    thread thread_1(threadFunc);
    thread thread_2(threadFunc);
    thread_1.join();
    thread_2.join();
    exit(EXIT_SUCCESS);
}