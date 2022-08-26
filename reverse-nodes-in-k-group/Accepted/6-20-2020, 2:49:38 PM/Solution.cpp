// https://leetcode.com/problems/reverse-nodes-in-k-group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head) return NULL;
      ListNode* prev=NULL;
      ListNode* next=NULL;
      ListNode* cur =head;
      int count =0;
      for(int i=0;i<k;i++){
            if(!cur) return head;
            cur=cur->next;
        }
      cur=head;
      for(int i=0;i<k;i++){
          if(!cur) break;
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head->next =reverseKGroup(next,k);
        return prev;
        
        
        
    }
};