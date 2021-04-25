#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

mutex g_mutex;

void threadFunc(void) {
    lock_guard<mutex> lock(g_mutex);    
    cout << this_thread::get_id() << endl;
}

int main() {
    thread thread_1(threadFunc);
    thread thread_2(threadFunc);
    cout << "this is main thread" << endl;
    thread_1.join();
    thread_2.join();
    exit(EXIT_SUCCESS);
}