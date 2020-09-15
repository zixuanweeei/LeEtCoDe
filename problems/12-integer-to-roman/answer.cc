#include <iostream>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    const int num_bin = 13;
    int bin[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ret;
    for (int i = 0; i < num_bin; ++i) {
      if (bin[i] <= num) {
        int scale = num / bin[i];
        num %= bin[i];
        while (scale--) ret += str[i];
      }
    }
    return ret;
  }
};

int main(int argv, char **argc) {
  int input = stoi(argc[1]);
  Solution sol;
  string ret = sol.intToRoman(input);

  std::cout << "Result is: " << ret << std::endl;
  return 0;
}
