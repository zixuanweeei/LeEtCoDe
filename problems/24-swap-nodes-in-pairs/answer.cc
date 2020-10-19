#include <iostream>

#include <ListNode.hpp>

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *new_head = head;

    ListNode *first = head;
    ListNode *end = nullptr;

    while (first) {
      ListNode *second = first->next;
      if (end) end->next = second;
      if (!second) {
        if (end) end->next = first;
        break;
      }
      ListNode *third = second->next;

      if (new_head == head) { new_head = second; }
      second->next = first;
      first->next = third;
      end = first;

      first = third;
    }
    return new_head;
  }
};
