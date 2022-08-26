// https://leetcode.com/problems/reorder-list

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
    
    ListNode* reverse(ListNode* head){
        ListNode* cur = head ;
        ListNode* prev = NULL ;
        ListNode* next ;
        
        while(cur!=NULL){
            next = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = next ;
        }
        
        head = prev ;
        return head ;
        
    }
    
    ListNode* merge(ListNode* l1,ListNode* l2){
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur ;
        cur = dummy ;
        bool flag = true ;
        while(l1!= NULL && l2!=NULL){
            
            if(flag){
                cur->next = l1 ;
                l1 = l1->next;
            }
            else {
                cur->next = l2 ;
                l2 = l2->next;
            }
            cur = cur->next ;
            flag = !flag ;
        }
        
        cur->next = l1 !=NULL ? l1 :l2;
        return dummy->next ;
        
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        
        while(fast && fast->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next;
        }
        
      
       ListNode* head1 = head ;
       ListNode* head2 = slow->next ;
     
       ListNode* reversedhalf = reverse(head2); 
       ListNode* merged = merge(head1,reversedhalf); 
    }
};