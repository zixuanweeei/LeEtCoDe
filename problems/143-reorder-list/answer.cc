#include <iostream>
#include <vector>

#include <ListNode.hpp>

using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head) return; 
    vector<ListNode *> node_vec;
    ListNode *node_ptr = head;
    while (node_ptr) {
      node_vec.push_back(node_ptr);
      node_ptr = node_ptr->next;
    }
    size_t length = node_vec.size();
    ListNode *tail = node_vec.back();
    size_t i = 0, j = length - 1;
    while (i < j) {
      node_vec[i]->next = node_vec[j];
      i++;
      if (i == j) break;
      node_vec[j]->next = node_vec[i];
      j--;
    }
    node_vec[i]->next = nullptr;
  }
};
