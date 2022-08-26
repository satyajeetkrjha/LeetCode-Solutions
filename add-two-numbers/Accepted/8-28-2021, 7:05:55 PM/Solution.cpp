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
        int carry =0 ;
        ListNode* cur ;
        ListNode* head=NULL;
        ListNode* dummyNode = new ListNode(0);
        cur = dummyNode ;
        while(l1 !=NULL || l2!=NULL){
            int x1 = l1!=NULL ?l1->val:0;
            int x2=  l2!=NULL ?l2->val:0;
            
            int val = (carry+x1+x2)%10;
            carry = (carry+x1+x2)/10;
            
            cur->next = new ListNode(val);
            cur = cur->next;
            
            if(l1!=NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2 = l2->next;
            }
            
        }
        if(carry!=0){
            cur->next = new ListNode(carry);
        }
        return dummyNode->next;
    }
};