#include <iostream>
#include <vector>

#include <Utils.hpp>

using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    // Create a array representing 0~100
    vector<int> cnt(101, 0);
    int n = nums.size();
    // Count for every entry of the input array
    for (int i = 0; i < n; i++) cnt[nums[i]]++;
    // Cumulate
    for (int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      ret.push_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
    }
    return ret;
  }
};

int main(int argv, char **argc) {
  vector<int> nums;
  for (size_t i = 1; i < argv; ++i) nums.push_back(stoi(argc[i]));
  Solution sol;
  auto ret = sol.smallerNumbersThanCurrent(nums);
  print_vector(ret);

  return 0;
}
