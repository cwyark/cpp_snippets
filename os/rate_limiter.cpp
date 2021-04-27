#include <iostream>
#include <thread>
#include <queue>
#include <chrono>

// reference: https://liam.page/2020/05/17/Implementing-a-Thread-safe-Rate-Limiter-in-C/

using namespace std;

class RateLimiter {
    public:
        RateLimiter(int max_request, chrono::milliseconds unit) {
            m_max_request = max_request;
            m_time_unit = unit;
        }
        bool canExecute() {
            auto now = chrono::high_resolution_clock::now();
            auto now_milli = now.time_since_epoch();
            chrono::duration<int, milli> timeDelta;
            {
                lock_guard<mutex> lock(m_mutex);
                auto firstTs = m_queue.back();
                timeDelta = now - firstTs;
            }
            if (timeDelta > m_time_unit) {
                // Can not be executated at this moment.
                return false;
            } else {
                // Can be executated at this moment.
                {
                    lock_guard<mutex> lock(m_mutex);
                    m_queue.push(now);
                }
                return true;
            }
        }
    private:
        queue<chrono::milliseconds> m_queue;
        chrono::milliseconds m_time_unit;
        int m_max_request;
        mutex m_mutex;
};

int main() {

}