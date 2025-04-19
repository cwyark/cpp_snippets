#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace ::std;

int main() {
  string s = "/h/./../fff//.../123";
  vector<string> tokens;
  stringstream ss(s);
  string token;
  while (getline(ss, token, '/')) {
    tokens.push_back(token);
  }

  for (const auto &t : tokens) {
    std::cout << t << std::endl;
  }

  for (auto it = tokens.begin(); it != tokens.end(); ++it) {
    cout << *it << endl;
  }

  // substr example
  string sss = "hello world";
  string sub = s.substr(0, 5);
  cout << "sub str is " << sub << endl;

  // compare example
  string sss_1 = "abcd", sss_2 = "bcda";
  if (sss_1.compare(sss_2) == 0) {
    cout << "Equal" << endl;
  } else if (sss_1.compare(sss_2) < 0) {
    cout << "a < b" << endl;
  } else {
    cout << "a > b" << endl;
  }

  string input = "1x 10 + 20 = 123";
  istringstream iss(input);
  vector<int> operands;
  vector<char> operators;
  int result = 0;
  while (iss >> token) {
    if (isdigit(token[0])) {
      operands.push_back(stoi(token));
    } else if (token == "x" || token == "+" || token == "-") {
      operators.push_back(token[0]);
    } else if (token == "=") {
      iss >> result;
      break;
    }
  }

  cout << "Operands: ";
  for (int n : operands)
    cout << n << " ";
  cout << "Operators: ";
  for (int n : operators)
    cout << n << " ";

  string sss_3 = "123";
  sss_3.pop_back();
  cout << sss_3 << endl;

  return 0;
}
