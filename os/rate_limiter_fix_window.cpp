#include <atomic>
#include <chrono>
#include <iostream>
#include <queue>
#include <thread>

// reference:
// https://liam.page/2020/05/17/Implementing-a-Thread-safe-Rate-Limiter-in-C/

using namespace std;

struct ms_clock {
  using rep = chrono::milliseconds::rep;
  using period = chrono::milliseconds::period;
  using duration = chrono::duration<rep, period>;
  using time_point = chrono::time_point<ms_clock, duration>;

  static time_point now() noexcept {
    return time_point(chrono::duration_cast<duration>(
        chrono::steady_clock::now().time_since_epoch()));
  }
};

class RateLimiter {
public:
  using clock = ms_clock;

private:
  uint32_t m_limit;
  clock::duration m_interval;
  clock::rep m_interval_count;

  mutable atomic<uint32_t> m_count{numeric_limits<uint32_t>::max()};
  mutable atomic<clock::rep> m_timestamp{0};

public:
  constexpr RateLimiter(uint32_t limit, clock::duration interval)
      : m_limit(limit), m_interval(interval),
        m_interval_count(interval.count()) {}
  RateLimiter(const RateLimiter &) = delete;
  RateLimiter &operator=(const RateLimiter &) = delete;
  RateLimiter(RateLimiter &&) = delete;
  RateLimiter &operator=(RateLimiter &&) = delete;
  bool operator()() const;
  double qps() const { return 1000.0 * this->m_limit / this->m_interval_count; }
};

bool RateLimiter::operator()() const {
  auto origin_count = this->m_count.fetch_add(1UL);
  if (origin_count < this->m_limit) {
    return true;
  } else {
    auto ts = this->m_timestamp.load();
    auto now = clock::now().time_since_epoch().count();
    if (now - ts < this->m_interval_count) {
      return false;
    }
    if (this->m_timestamp.compare_exchange_strong(ts, now)) {
      return false;
    }
    this->m_count.store(1UL);
    return true;
  }
}

int main() {}
