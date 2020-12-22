
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (!root) return ret;

    queue<TreeNode *> node_queue;
    node_queue.push(root);
    bool is_left2right = true;

    while (!node_queue.empty()) {
      deque<int> inter_ret;
      int cur_size = node_queue.size();

      while (cur_size--) {
        TreeNode *node = node_queue.front();
        node_queue.pop();

        if (is_left2right) {
          inter_ret.push_back(node->val);
        } else {
          inter_ret.push_front(node->val);
        }

        if (node->left) node_queue.push(node->left);
        if (node->right) node_queue.push(node->right);
      }
      ret.emplace_back(vector<int>{inter_ret.begin(), inter_ret.end()});
      is_left2right = !is_left2right;
    }
    return ret;
  }
};
