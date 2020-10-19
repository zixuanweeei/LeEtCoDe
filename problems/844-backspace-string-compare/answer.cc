#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    stack<char> s_stack;
    for (auto c : S) {
      if (c != '#')
        s_stack.push(c);
      else if (!s_stack.empty())
        s_stack.pop();
    }
    stack<char> t_stack;
    for (auto c : T) {
      if (c != '#')
        t_stack.push(c);
      else if (!t_stack.empty())
        t_stack.pop();
    }
    if (t_stack.size() != s_stack.size())
      return false;
    size_t len = t_stack.size();
    for (size_t i = 0; i < len; ++i) {
      if (s_stack.top() != t_stack.top())
        return false;
      s_stack.pop();
      t_stack.pop();
    }
    return true;
  }
};

int main(int argv, char **argc) {
  if (argv < 3)
    std::abort();
  string s = argc[1];
  string t = argc[2];
  Solution sol;
  bool ret = sol.backspaceCompare(s, t);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
