// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    
    ListNode* middle(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next ;
            fast = fast->next->next;
         }
        return slow ;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* cur = head ;
        ListNode *prev =NULL;
        ListNode* next ;
        while(cur!=NULL){
            next = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = next;
        }
        head = prev ;
        return head ; // start 
    }
    
    
    
    int pairSum(ListNode* head) {
        ListNode* mid = middle(head);
        ListNode* rev = reverse(mid);
        ListNode* cur = head;
        int maxsum = INT_MIN ;
        while(cur!=NULL && rev!=NULL){
            maxsum = max(maxsum ,cur->val+rev->val);
            cur = cur->next ;
            rev = rev->next ;
        }
        return maxsum ;
    
    }
};