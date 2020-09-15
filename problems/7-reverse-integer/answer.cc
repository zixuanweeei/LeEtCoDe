#include <iostream>
#include <string>

class Solution {
public:
  int reverse(int x) {
    int ret = 0;
    int res = x;
    int div = x;
    int base = 1;
    do {
      res = div % 10;
      div = div / 10;
      if (ret < -214748364 || ret > 214748364) {
        ret = 0;
        break;
      } 
      ret = res + ret * 10;
    } while (div);
    return ret;
  }
};

int main(int argv, char** argc) {
  const int in = std::stoi(argc[1]);
  Solution sol;
  const int ret = sol.reverse(in);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
