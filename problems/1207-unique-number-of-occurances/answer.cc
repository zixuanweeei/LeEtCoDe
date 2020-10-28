#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> occur;
    for (const auto &x : arr) { occur[x]++; }
    unordered_set<int> times;
    for (const auto &x : occur) { times.insert(x.second); }
    return times.size() == occur.size();
  }
};

/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/unique-number-of-occurrences/solution/du-yi-wu-er-de-chu-xian-ci-shu-by-leetcode-solutio/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
