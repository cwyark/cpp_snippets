#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <vector>

using namespace std;

mutex g_mutex;
condition_variable g_condition;

void threadFunc(void) {
    cout << this_thread::get_id() << " thread started" << endl;
    unique_lock<mutex> lock(g_mutex);
    g_condition.wait(lock);
    cout << this_thread::get_id() << " thread end" << endl;
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 3; i++) {
        thread t(threadFunc);
        threads.push_back(t);
    }

    for (int i = 0; i < 3; i++) {
        g_condition.notify_one();
        this_thread::sleep_for(chrono::seconds(2));
    }

    for (auto & t : threads) {
        t.join();
    }
    exit(EXIT_SUCCESS);
}