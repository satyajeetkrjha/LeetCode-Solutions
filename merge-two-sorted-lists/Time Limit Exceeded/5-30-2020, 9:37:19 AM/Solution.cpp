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
      ListNode* first =l1;
      ListNode* second =l2;
      ListNode* res;
        if(first==NULL){
            return second;
        }
        else if(second==NULL){
            return first;
        }
        res=NULL;
        if(first->val<=second->val){
            res=first;
            res->next=mergeTwoLists(first,second->next);
        }
        else {
            res=second;
            res->next =mergeTwoLists(first->next,second);
        }
        return res;
    }
};