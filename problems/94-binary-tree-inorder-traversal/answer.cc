#include <iostream>
#include <stack>
#include <vector>

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
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> node_stack;
    vector<int> ret;
    TreeNode *node;
    node = root;
    while (node || !node_stack.empty()) {
      if (node) {
        node_stack.push(node);
        node = node->left;
      } else {
        TreeNode *top = node_stack.top();
        ret.push_back(top->val);
        node_stack.pop();
        node = top->right;
      }
    }
    return ret;
  }
};