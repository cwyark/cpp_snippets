#include <array>
#include <iostream>
#include <string>

class Permutation {
private:
  std::string current;
  std::string first;

public:
  explicit Permutation(std::string str) : current(str), first(str) {
    // sort first into the initial lexicographical order.
    std::sort(first.begin(), first.end());
  }

  // show next `lexicographical order` (dictionary order).
  void next() {
    int n = static_cast<int>(current.size());
    int i = n - 2;
    // step 1 : find the right most curr[i + 1] > curr[i]
    while (i >= 0 && current.at(i) >= current.at(i + 1)) {
      i--;
    }

    if (i < 0) {
      reset();
      return;
    }

    // step 2 : find the right most curr[j] > curr[i]
    int j = n - 1;
    while (current.at(j) <= current.at(i)) {
      j--;
    }

    // step 3: swap
    std::swap(current[i], current[j]);

    // step 4: reverse
    std::reverse(current.begin() + i + 1, current.end());
  };

  // reset to first.
  void reset() { current = first; };

  // return current permutation.
  const std::string &value() const { return current; };

  // a static helper function to check two string are permutation.
  // Time Complexity: O(N).
  // Space Complexity: O(1), fixed at 256 size.
  static bool isPermutation(std::string_view a, std::string_view b) {
    // first check wether their size equal or not.
    // if not equal, then they are not permutation.
    if (a.size() != b.size())
      return false;
    // create a continuous memory and the index will
    // be the characters.
    std::array<int, 256> arr{};
    for (unsigned char c : a) {
      ++arr[c];
    }
    for (unsigned char c : b) {
      // early return false when detect some character
      // counter is not equal.
      if (--arr[c] < 0)
        return false;
    }
    for (int counter : arr) {
      if (counter != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::cout << "use STL permutation first" << std::endl;
  std::string s = "abc";
  do {
    std::cout << s << std::endl;
  } while (std::next_permutation(s.begin(), s.end()));
  std::string ss = "bca";
  std::cout << "check " << ss << " is " << s << " permutation "
            << std::is_permutation(s.begin(), s.end(), ss.begin()) << std::endl;
  std::cout << "Use custom permutation" << std::endl;
  auto perm = Permutation("bca");
  std::cout << perm.value() << std::endl;
  perm.next();
  std::cout << perm.value() << std::endl;
  return 0;
}
