#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    const size_t name_len = name.size();
    const size_t typed_len = typed.size();
    size_t name_idx = 0;
    size_t typed_idx = 0;

    while (name_idx < name_len || typed_idx < typed_len) {
      if (name[name_idx] == typed[typed_idx]) {
        name_idx++;
        typed_idx++;
      } else if (typed_idx > 0 && typed[typed_idx] == typed[typed_idx - 1]) {
        typed_idx++;
      } else {
        return false;
      }
    }
    return name_idx == name_len && typed_idx == typed_len;
  }
};

int main(int argv, char **argc) {
  string name = argc[1];
  string typed = argc[2];

  Solution sol;
  bool ret = sol.isLongPressedName(name, typed);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
