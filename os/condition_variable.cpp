#include <iostream>
#include <mutex>
#include <future>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex g_mutex;
condition_variable g_condition;

void threadFunc(void) {
    cout << this_thread::get_id() << " thread started." << endl;
    unique_lock<mutex> lock(g_mutex);
    g_condition.wait(lock);
    cout << this_thread::get_id() << " thread ended." << endl;
}

int main() {
    cout << "Create new thread" << endl;
    thread t1(threadFunc);

    cout << "Wait for 1 seconds" << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "send notify" << endl;
    g_condition.notify_all();

    t1.join();
    exit(EXIT_SUCCESS);
}