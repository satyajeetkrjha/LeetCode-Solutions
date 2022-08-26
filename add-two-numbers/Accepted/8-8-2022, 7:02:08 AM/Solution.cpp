// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur ;
        cur = dummy ;
        int sum{0};
        int carry{0};
        
        while(l1!=NULL ||  l2!=NULL){
            
            int x = l1!=NULL ? l1->val:0;
            int y = l2!=NULL ? l2->val:0;
            
            sum   = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            
            cur->next = new ListNode(sum);
            cur = cur->next;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        
        if(carry !=0)
            cur->next = new ListNode(carry);
        return dummy->next ;
        
        
    }
};