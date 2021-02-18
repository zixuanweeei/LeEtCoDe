#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int minKBitFlips(vector<int>& A, int K) {
    int n = A.size();
    queue<size_t> que;
    int res = 0;
    for (size_t i = 0; i < n; ++i) {
      if (!que.empty() && i >= que.front() + K) {
        que.pop();
      }
      if (que.size() % 2 == A[i]) {
        if (i + K > n) return -1;
        que.push(i);
        res++;
      }
    }
    return res;
  }
};
