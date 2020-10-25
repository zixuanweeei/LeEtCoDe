#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    vector<bool> ret;
    for (size_t i = 0; i < l.size(); ++i) {
      size_t left = l[i];
      size_t right = r[i];
      if (right - left < 2) {
        ret.push_back(true);
        continue;
      };
      vector<int> tmp_nums(nums.begin() + left, nums.begin() + right + 1U);
      sort(tmp_nums.begin(), tmp_nums.end());

      int last_diff = tmp_nums[1] - tmp_nums[0];
      for (size_t idx = 2; idx < tmp_nums.size(); ++idx) {
        if (tmp_nums[idx] - tmp_nums[idx - 1] != last_diff) {
          ret.push_back(false);
          break;
        }
      }
      if (ret.size() < i + 1) ret.push_back(true);
    }
    return ret;
  }
};
