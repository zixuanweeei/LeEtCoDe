#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int stack[10];
    int top = 0;
    while (x) {
      stack[top++] = x % 10;
      x /= 10;
    }
    int digit = top - 1;
    while (top--) {
      if (stack[digit - top] != stack[top]) return false;
    }
    return true;
  }
};

int main(int argv, char** argc) {
  const int in = std::stoi(argc[1]);
  Solution sol;
  const bool ret = sol.isPalindrome(in);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
