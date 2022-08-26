// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len =0;
      ListNode* cur = head ;
        
        while(cur!=NULL){
            cur = cur->next ;
            len++;
        }
        cur = head ;
        int move = len -n -1;
        while(move>0){
            cur = cur->next;
            move--;
        }
        cout <<"cur->val is "<< cur->val << endl;
       
        ListNode* nextofnext = cur->next->next ;
        cur->next = nextofnext ;
        return  head ;
    }
};