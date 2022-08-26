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
    
    int findlength(ListNode* head){
        int len =0 ;
        ListNode* cur = head ;
        while(cur!=NULL){
            len++;
            cur = cur->next;
        }
        return len ;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int len = findlength(head);
        cout <<"len is "<< len << endl;
        int num  = len -k-1;
        ListNode* cur = head;
        while(num >0){
            cur = cur->next;
            num --;
        }
        cout <<"val is "<< cur->val <<endl;
        cur->next = cur->next->next ;
       
        return head ;
    }
};