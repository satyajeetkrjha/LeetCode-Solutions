// https://leetcode.com/problems/reorder-list

class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    ListNode *cur = head, *prev = NULL;

    while (cur != NULL) {
      auto next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    head = prev ;
      return head ;
  }

  void merge(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
      auto next_l1 = l1->next ;
      auto next_l2 = l2->next ;
      l1->next = l2;
      l2->next = next_l1;
      l1 = next_l1 ;
      l2 = next_l2 ;  
    }
  }

  void reorderList(ListNode* head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto head1 = head, head2 = slow->next;
    slow->next = NULL;
    
    ListNode* reversedhalf = reverse(head2);
    merge(head1, reversedhalf);
  }
};