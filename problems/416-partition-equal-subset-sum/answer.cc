#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    size_t n = nums.size();
    if (n < 2)
      return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maximum = *max_element(nums.begin(), nums.end());
    if (sum & 1)
      return false;
    int target = sum / 2;
    if (maximum > target)
      return false;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (size_t i = 0; i < n; ++i) dp[i][0] = true;
    dp[0][nums[0]] = true;
    for (size_t i = 1; i < n; ++i) {
      int num = nums[i];
      for (int j = 1; j <= target; ++j) {
        if (j >= num) {
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }
};

int main(int argv, char **argc) {
  vector<int> nums;
  for (size_t i = 1; i < argv; ++i) {
    nums.push_back(stoi(argc[i]));
  }
  Solution sol;
  bool ret = sol.canPartition(nums);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
