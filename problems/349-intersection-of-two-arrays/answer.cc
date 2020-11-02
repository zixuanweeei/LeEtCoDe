#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> num_set(nums1.begin(), nums1.end());
    set<int> ret;
    for (auto num : nums2) {
      if (num_set.count(num)) ret.insert(num);
    }
    return {ret.begin(), ret.end()};
  }
};