#include <iostream>
#include <stack>
#include <vector>

#include <TreeNode.hpp>

using namespace std;

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    TreeNode *node = root;
    stack<TreeNode *> node_stack;
    vector<int> ret;
    while (node || !node_stack.empty()) {
      if (node) {
        node_stack.push(node);
        ret.push_back(node->val);
        node = node->left;
      } else {
        TreeNode *top = node_stack.top();
        node_stack.pop();
        node = top->right;
      }
    }
    return ret;
  }
};
