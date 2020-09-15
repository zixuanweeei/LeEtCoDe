#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    auto left_it = height.begin();
    auto right_it = height.end() - 1;
    int top = 0;
    for (auto &v : height) {
      top = top > v ? top : v;
    }
    int max_area = 0;
    for (int i = 0; i <= top; ++i) {
      for ( ; *left_it < i; left_it++) ;
      for ( ; *right_it < i; right_it--) ;
      int new_area = distance(left_it, right_it) * i;
      max_area = max_area > new_area ? max_area : new_area;
    }
    return max_area;
  }
};

int main(int argv, char **argc) {
  std::vector<int> inputs;
  int num_bins = argv - 1;
  for (int i = 0; i < num_bins; ++i) {
    inputs.push_back(stoi(argc[i + 1]));
  }
  Solution sol;
  int ret = sol.maxArea(inputs);
  std::cout << "Solution is: " << ret << std::endl;
  return 0;
}
