#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

using namespace std;

// reference: https://liam.page/2020/10/14/implement-a-timed-looper-in-cxx/

class Timer{
    public:
        explicit Timer(chrono::milliseconds msecs) : m_msecs(msecs) {}
        ~Timer() {
            if (m_thread.joinable()) {
                terminate();
                m_thread.join();
            }
        }

        void terminate() {
            {
                lock_guard<mutex> lock(m_mutex);
                running = false;
            }
            m_lock.notify_all();
        }

        void launch() {
            m_thread = move(thread(&Timer::loop, this));
        }

        void loop() {
            unique_lock<mutex> _lock;
            while(m_lock.wait_for(_lock, m_msecs, [this]() {
                return !this->running;
            })) {
                cout << "Timer !" << endl;
            }
        }

    private:
        chrono::milliseconds m_msecs;
        bool running = false;
        thread m_thread;
        mutable mutex m_mutex;
        mutable condition_variable m_lock;
};

int main() {

}