/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *convertBST(TreeNode *root) {
    stack<TreeNode *> node_stack;
    TreeNode *node = root;
    int tmp = 0;
    while (node || !node_stack.empty()) {
      if (node) {
        node_stack.push(node);
        node = node->right;
      } else {
        TreeNode *top = node_stack.top();
        tmp += top->val;
        top->val = tmp;
        node_stack.pop();
        node = top->left;
      }
    }
    return root;
  }
};