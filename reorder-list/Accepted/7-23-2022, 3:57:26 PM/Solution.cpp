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
        ListNode* prev = NULL ;
        ListNode* cur = head ;
       
        while(cur!=NULL){
            ListNode* next = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = next;
        }
        head = prev ;
        return head ;
    }
    
    void merge(ListNode* l1,ListNode* l2){
        while(l1 && l2){
            auto next_l1 = l1->next ;
            auto next_l2  = l2->next ;
            l1->next = l2 ;
            l2->next = next_l1 ;
            l1 = next_l1 ;
            l2 = next_l2 ;
        }
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next ;
            fast = fast->next->next;
        }
        auto head1 =head ;
        auto head2 = slow->next;
        slow->next  =NULL ;
        
        ListNode* reversedhead = reverse(head2);
        merge(head1,reversedhead);
        
    }
};