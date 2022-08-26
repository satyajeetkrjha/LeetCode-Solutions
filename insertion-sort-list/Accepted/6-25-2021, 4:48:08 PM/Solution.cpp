// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy ;
        ListNode* cur = head ;
        ListNode* next;
        
        while(cur!=NULL){
            next = cur->next ;
            while(prev->next!=NULL && prev->next->val <cur->val){
                prev = prev->next;
            }
           
            cur->next = prev->next;
            if(cur->next)
            cout<<"cur->next val is "<<cur->next->val <<endl;
            else 
                cout<<"cur->next val is NULL"<<endl;
            
            prev->next = cur;
            
            prev = dummy ;
            cur = next;
        }
        return dummy->next ;
    }
};