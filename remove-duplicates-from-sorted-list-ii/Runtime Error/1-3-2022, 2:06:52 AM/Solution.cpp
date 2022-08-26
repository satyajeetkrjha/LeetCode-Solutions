// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *dummy = new ListNode(0);
      dummy->next = head ;
      ListNode*cur = dummy;
      while(cur!=NULL && cur->next->next!= NULL){
          if(cur->next->val == cur->next->next->val){
              int duplicatevalue = cur->next->val;
              while(cur->next!=NULL && cur->next->val == duplicatevalue){
                  cur->next = cur->next->next;
              }
          }
          else{
              cur = cur->next;
          }
      }
        return dummy->next ;
        
        
    }
};