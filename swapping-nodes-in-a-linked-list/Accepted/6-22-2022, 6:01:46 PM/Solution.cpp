// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head ;
        ListNode* ptr2 = head ;
        ListNode* kth;
        for(int i= 1;i<k;i++){
            ptr1 = ptr1->next;
        }
        
        // now ptr1 is pointing to the kth node exactly
        kth = ptr1 ;
        // now to make ptr2 node k nodes behind ptr1 ,we move ptr1 by 1 step 
        ptr1 = ptr1->next ;
        
        while(ptr1!=NULL){
           ptr1 = ptr1->next ;
            ptr2 =ptr2->next;
        }
        
        swap(ptr2->val,kth->val);
        
        return head ;
        
    }
};