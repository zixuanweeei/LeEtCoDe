#include <iostream>
#include <stack>

#include <TreeNode.hpp>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    int minimum = 1000000;
    int tmp = -1;
    TreeNode *node = root;
    stack<TreeNode *> node_stack;
    while (node || !node_stack.empty()) {
      if (node) {
        node_stack.push(node);
        node = node->left;
      } else {
        node = node_stack.top();
        if (tmp == -1) {
          tmp = node->val;
        } else {
          int cur = node->val - tmp;
          tmp = node->val;
          minimum = min(cur, minimum);
        }
        node_stack.pop();
        node = node->right;
      }
    }
    return minimum;
  }
};
