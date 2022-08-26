// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
       ListNode* dummy1 =new ListNode(0);
       ListNode* dummy2 =new ListNode(0);
       ListNode* before =dummy1;
       ListNode* after =dummy2;
       while(head){
           if(head->val<x){
               before->next= new ListNode(head->val);
               before =before->next;
               head=head->next;
               
           }
           else {
               after->next = new ListNode(head->val);
               after =after->next;
               head=head->next;
           }
       }
        after->next=NULL;
        before->next =dummy2->next;
        return dummy1->next;
        
    }
};