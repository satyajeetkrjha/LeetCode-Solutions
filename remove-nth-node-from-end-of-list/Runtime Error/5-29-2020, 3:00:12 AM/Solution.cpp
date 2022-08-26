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
#include <iostream>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int len =0;
       ListNode *cur =head;
       
        while(cur!=NULL){
            len++;
            cur =cur->next;
        }

        int steps =len -n-1;
        
        cur=head;
        while(steps>0){
            cur =cur->next;
            steps --;
        }
        cur->next =cur->next->next;
        
        return head;
        
        
    }
};