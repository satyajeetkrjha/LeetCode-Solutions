// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(cur ==NULL)
            return NULL ;
        ListNode* cur = head ;
        int len =1 ;
        while(cur->next!=NULL){
            cur = cur->next ;
            len ++;
        }
       
        //cout <<"len is "<< len << endl;
        //cout <<"val is "<< cur->val << endl;
        cur->next = head ;
        k = k % len ;
       
        k = len -k;
        //cout <<" k is "<< k <<endl;
        while(k--){
            cur = cur->next ;
        }
        head = cur->next ;
        cur->next = NULL ;
        return head ;
        
    }
};