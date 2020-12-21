#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    const int len = cost.size();
    for (int i = 2; i < len; ++i) {
      cost[i] = cost[i] + (cost[i - 1] > cost[i - 2] ? cost[i - 2] : cost[i - 1]);
      // std::cout << cost[i] << ", " << std::endl;
    }
    return cost[len - 1] > cost[len - 2] ? cost[len - 2] : cost[len - 1];
  }
};

int main(int argv, char **argc) {
  vector<int> cost;
  for (int i = 1; i < argv; ++i) {
    cost.push_back(stoi(argc[i]));
  }
  int ret = Solution().minCostClimbingStairs(cost);
  std::cout << "Result: " << ret << std::endl;

  return 0;
}
