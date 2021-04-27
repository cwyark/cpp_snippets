#include <iostream>
#include <queue>
#include <condition_variable>

// Reference: https://chenlen.com/task-queue-任務隊列/

using namespace std;

class TaskQueue {
    public:
    void put(const string & s) {
        {
            lock_guard<mutex> lock(m_mutex);
            m_queue.push(s);
        }
        m_condition.notify_one();
    }

    string take() {
        unique_lock<mutex> lock(m_mutex);
        m_condition.wait(lock, [this]() {
            return !this->m_queue.empty();
        });
        string s = m_queue.front();
        m_queue.pop();
        return s;
    }

    private:
    mutex m_mutex;
    condition_variable m_condition;
    queue<string> m_queue;
};

int main() {

}