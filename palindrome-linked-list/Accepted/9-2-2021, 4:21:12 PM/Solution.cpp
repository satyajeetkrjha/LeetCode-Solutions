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
    int lengthoflinkedlist(ListNode* head){
        ListNode* cur = head ;
        int l =0 ;
        while( cur!=NULL){
            cur = cur->next ;
            l++;
        }
        return l;
    }
    
    ListNode* middleoflinkedlist(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast !=NULL && fast->next !=NULL){
            slow = slow ->next ;
            fast = fast->next->next;
        }
        return slow ;
    }
    
    ListNode* reverseLinkedList(ListNode* head){
        
        // cout<<"called"<<endl;
        ListNode* prev = NULL;
        ListNode* cur= head;
        ListNode* next;
        while(cur!=NULL){
            // store the address of the next node
            next = cur->next ;
            // break the link by making it point to null
            cur->next = prev ;
            prev = cur;
            cur=next;
        }
        head = prev;
        // cout<<"head->val is "<<head->val<<endl;
        return head ;
        
    }
    
    void printLinkedList(ListNode* head){
        ListNode* cur = head ;
        while(cur!=NULL){
            cout<<cur->val<<" ";
            cur = cur->next ;
        }
        cout<<endl;
        cout<<"------"<<endl;
    }
    
    bool isPalindrome(ListNode* head) {
        // first find the length of the linked list .Next ,find the middle portion of the linked list and reverse the middle half .Now compare the two .
        int len =lengthoflinkedlist(head);
        ListNode* mid =middleoflinkedlist(head);
        // printLinkedList(mid);
        mid = reverseLinkedList(mid);
        // printLinkedList(mid);
        
        int count = 0 ;
        ListNode* cur = head;
        while(count <len/2){
            if(cur->val !=mid->val){
                return false;
            }
            cur = cur->next ;
            mid= mid->next ;
            count++;
        }
        return true ;
    }
};