#include <iostream>

using namespace std;

// string 1 => ABCDE
//             ^
//             i = 0
// string 2 => BCD
//             ^
//             j = 0

// string 1 => ABCDE
//              ^
//              i = 1
// string 2 => BCD
//             ^
//             j = 0

// string 1 => ABCDE
//               ^
//              i = 2
// string 2 => BCD
//              ^
//             j = 1

// string 1 => ABCDE
//                ^
//               i = 3
// string 2 => BCD
//               ^
//              j = 2

bool checkPermutionFromStrings(std::string _str1, std::string _str2) {
    int len_of_str1 = _str1.length();
    int len_of_str2 = _str2.length();
    bool _compared_result = false;
    for (int i = 0; i < len_of_str1; i++) {
        for (int j = 0; j < len_of_str2; j++) {
            if (_str1[i] == _str2[j]) {
                _compared_result = true;
                continue;
            } else {
                _compared_result = false;
            }
        }
    }
    return _compared_result;
}

int main(int argc, char * argv[]) {
    std::string _str1 = "ABCDE";
    std::string _str2 = "BCD";
    if (checkPermutionFromStrings(_str1, _str2) == true) {
        std::cout << "one string is permution of other" << std::endl;
    } else {
        std::cout << "one string is not permution of other" << std::endl;
    }
}

1 1 1 
2 2 2 
3 3 3 

3 2 1
3 2 1 
3 2 1 

(i, j) => (j, i)