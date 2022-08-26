// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* cur = head ;
        
        while(m >1){
            prev = cur ;
            cur = cur->next ;
            m -- ;
            n --;
        }
        
        ListNode* conn = prev ;
        ListNode* tail = cur;
        
        ListNode* nextofnext = NULL;
        while(n >0){
            nextofnext = cur->next ;
            cur->next = prev;
            prev = cur ;
            cur = nextofnext;
            n --;
        }
        
        if(conn!=NULL){
            conn->next = prev;
        }
        else{
            head = prev;
        }
        
        tail->next = cur ;
        return head ;
        
    }
};