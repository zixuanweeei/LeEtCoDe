#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
  vector<vector<int>> ret;
  
  void dfs(vector<int> &candidates, int target, vector<int> &state, int start) {
    if (target == 0) {
      ret.emplace_back(state.begin(), state.end());
    } else if (0 < target) {
      for (int i = start; i < candidates.size(); ++i) {
        int res = target - candidates[i];
        if (res < 0) continue;
        state.push_back(candidates[i]);
        dfs(candidates, res, state, i);
        state.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    for (int i = 0; i < candidates.size(); ++i) {
      vector<int> state;
      state.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], state, i);
    }
    return ret;
  }
};

int main(int argv, char **argc) {
  int target = stoi(argc[1]);
  vector<int> candidates;
  for (int i = 2; i < argv; ++i) {
    candidates.push_back(stoi(argc[i]));
  }
  Solution sol;
  auto ret = sol.combinationSum(candidates, target);
  cout << "Solution is:\n[\n";
  for (auto &v : ret) {
    cout << "  [";
    for (auto i : v) cout << i << ", ";
    cout << "],\n";
  }
  cout << "]" << endl;
  
  return 0;
}
