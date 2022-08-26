// https://leetcode.com/problems/palindrome-linked-list

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
    
    int findlen(ListNode* head){
        
        int len =0 ;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        
        return len ;
    }
    
    ListNode* half(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev =NULL;
        ListNode* cur = head ;
        ListNode* next ;
        while(cur){
            next = cur->next ;
            cur->next = prev ;
            prev = cur;
            cur = next;
        }
        head = prev ;
        return head ;
    }
    bool isPalindrome(ListNode* head) {
        
        int len = findlen(head);
        ListNode* mid = half(head);
        mid = reverse(mid);
        int c = 0 ;
        ListNode* cur = head ;
        while( c< len/2){
            if(mid->val != cur->val){
                return false;
            }
            cur = cur->next ;
            mid = mid->next;
            c++;
        }
        return true;
        
        
        
    }
};