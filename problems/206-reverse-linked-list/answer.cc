#include <iostream>

#include <ListNode.hpp>

using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur) {
      ListNode *tail = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tail;
    }
    return pre;
  }
};
