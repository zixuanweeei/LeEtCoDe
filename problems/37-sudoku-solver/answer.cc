#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  bool row[9][9];
  bool col[9][9];
  bool blk[3][3][9];
  bool valid = false;
  vector<pair<int, int>> spaces;

  void dfs(vector<vector<char>> &board, int pos) {
    if (pos == spaces.size()) {
      valid = true;
      return;
    }

    int i = spaces[pos].first;
    int j = spaces[pos].second;

    for (int digit = 0; digit < 9 && !valid; ++digit) {
      if (!row[i][digit] && !col[j][digit] && !blk[i / 3][j / 3][digit]) {
        row[i][digit] = col[j][digit] = blk[i / 3][j / 3][digit] = true;
        board[i][j] = digit + '0' + 1;
        dfs(board, pos + 1);
        row[i][digit] = col[j][digit] = blk[i / 3][j / 3][digit] = false;
      }
    }
  }

  void solveSudoku(vector<vector<char>> &board) {
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(blk, false, sizeof(blk));
    valid = false;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          spaces.emplace_back(i, j);
        } else {
          int digit = board[i][j] - '0' - 1;
          row[i][digit] = col[j][digit] = blk[i / 3][j / 3][digit] = true;
        }
      }
    }
    dfs(board, 0);
  }
};
