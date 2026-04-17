#include <iostream>
#include <string>
#include <vector>

void backtracking(std::string &s, std::string &perm,
                  std::vector<std::string> &perms, std::vector<bool> &used) {
  int n = static_cast<int>(s.size());
  if (s.size() == perm.size()) {
    perms.push_back(perm);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (used[i])
      continue;
    used[i] = true;
    perm.push_back(s[i]);
    backtracking(s, perm, perms, used);
    perm.pop_back();
    used[i] = false;
  }
}

int main() {
  std::string s = "abc";
  std::string perm;
  std::vector<std::string> perms;
  std::vector<bool> used(s.size(), false);
  backtracking(s, perm, perms, used);
  for (auto perm : perms) {
    std::cout << perm << std::endl;
  }
  return 0;
}
