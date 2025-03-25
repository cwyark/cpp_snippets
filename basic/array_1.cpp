#include <iostream>

/*
 * Hash table could be implmented in a array and hash function
 * In general, HashTable look up time is O(1),  constant time
 * But when numbers of key growing, we can use linked list to prevent conflict,
 * look up time will be O(N) Or We can use Balanced Binary Search Tree, which
 * look up time will be O(logN)
 *
 */

bool checkStringUnique(std::string &_str) {
  int len = _str.length();
  for (int i = 0; i < (len - 1); i++) {
    for (int j = (i + 1); j < len; j++) {
      if (_str[i] == _str[j]) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::string _string = "abcde";
  if (checkStringUnique(_string) == false) {
    std::cout << "Found duplicated char !" << std::endl;
  } else {
    std::cout << "All chars are unique!!" << std::endl;
  }
  exit(0);
}
