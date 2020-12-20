#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    size_t last_idx[26] = {0};
    bool visited[26] = {false};
    stack<char> container;

    for (size_t i = 0; i < s.size(); ++i) { last_idx[s[i] - 'a'] = i; }

    for (size_t i = 0; i < s.size(); ++i) {
      const char cur = s[i];
      if (!visited[cur - 'a']) {
        while (!container.empty() && container.top() > cur) {
          if (last_idx[container.top() - 'a'] > i) {
            visited[container.top() - 'a'] = false;
            container.pop();
          } else {
            break;
          }
        }
        visited[cur - 'a'] = true;
        container.push(cur);
      }
    }
    string ret;
    while (!container.empty()) {
      ret.insert(ret.begin(), container.top());
      container.pop();
    }
    return ret;
  }
};

int main(int argv, char **argc) {
  string s = argc[1];
  string ret = Solution().removeDuplicateLetters(s);

  std::cout << "Result: " << ret << std::endl;

  return 0;
}
