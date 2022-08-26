// https://leetcode.com/problems/plus-one-linked-list

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
    ListNode* plusOne(ListNode* head) {
      // dummy node with value zero and make it point to the head   
      ListNode* sentinel = new ListNode(0);
      sentinel->next = head ;
      ListNode* notnine = sentinel ;
       
      while(head!= NULL){
          if(head->val !=9){
              notnine = head;
          }
          head = head ->next;
      }
        
        notnine->val ++;
        notnine = notnine->next;
        
        // make all 9 as zero now 
        while(notnine != NULL){
            notnine->val =0;
            notnine = notnine->next;
        }
        return sentinel->val == 0 ? sentinel->next :sentinel;
        
    }
};