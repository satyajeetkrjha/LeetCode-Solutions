// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur ;
        cur = dummy ;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <=l2->val){
                cur->next = l1;
                l1 = l1->next;
                
            }else{
                cur->next =l2;
                l2= l2->next;
            }
            cur=cur->next;
        }
        cur->next = l1 == NULL ?l2:l1;
        return dummy->next;
    }
};