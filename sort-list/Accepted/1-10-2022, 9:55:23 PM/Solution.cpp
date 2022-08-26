// https://leetcode.com/problems/sort-list

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
    
    ListNode* merge(ListNode* l1 ,ListNode* l2){
        if(l1 == NULL) return l2 ;
        if(l2 == NULL) return l2 ;
        
        ListNode* head =NULL;
        if(l1->val < l2->val){
            head = l1 ;
            l1 = l1->next;
        }
        else{
            head = l2 ;
            l2 = l2->next;
        }
        
        ListNode* p = head ;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1 ;
                l1 = l1->next;
            }
            else{
                p->next = l2 ;
                l2 = l2 ->next;
            }
              p = p->next ;
        }
        
        if(l1){
            p->next = l1 ;
        }
        else {
            p->next = l2 ;
        }
      
        return head ;
        
    }
    
    ListNode* sortList(ListNode* head) {
    
        if (head == NULL || head->next == NULL)
                return head;
        
        ListNode* slow = head ;
        ListNode* fast = head->next ;
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
        }
        
        // slow points to the middle of the linked list 
        fast = slow->next ;
        slow->next =NULL;
        
        return merge(sortList(head) ,sortList(fast));
        
    }
};