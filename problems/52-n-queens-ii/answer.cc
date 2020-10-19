#include <iostream>
#include <vector>

class Solution {
public:
  void backtracing(const int y, const int n) {
    if (y == n) {
      count++;
      return;
    }
    for (int x = 0; x < n; ++x) {
      if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) { continue; }
      column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
      backtracing(y + 1, n);
      column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
  }

  int totalNQueens(int n) {
    count = 0;
    column.assign(n, 0);
    diag1.assign(n + n, 0);
    diag2.assign(n + n, 0);
    backtracing(0, n);
    return count;
  }
  int count;
  std::vector<int> column;
  std::vector<int> diag1;
  std::vector<int> diag2;
};

int main(int argv, char **argc) {
  int n = std::stoi(argc[1]);
  Solution sol;
  int ret = sol.totalNQueens(n);
  std::cout << "Result is: " << ret << std::endl;

  return 0;
}
