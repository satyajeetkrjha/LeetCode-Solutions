// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* reverseLinkedList(ListNode* head){
       ListNode* prev =NULL;
       ListNode* cur = head;
       ListNode* next ;
       while(cur!=NULL){
           next = cur->next ;
           cur->next =prev;
           prev=cur;
           cur=next;
       }
        head = prev;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       l1=reverseLinkedList(l1);
       l2=reverseLinkedList(l2);
      
       ListNode* cur;
       int carry =0;
        ListNode* head=NULL;
       while(l1!=NULL || l2!=NULL){
           int x1=  l1 !=NULL ? l1->val :0;
           int x2=  l2 !=NULL ? l2->val: 0;
           int sum = (carry+x1+x2)%10;
           carry = (carry+x1+x2)/10;
           
           cur = new ListNode(sum);
           cur->next = head ;
           head = cur; 
           
           l1 = l1!=NULL ? l1->next:NULL;
           l2 = l2!=NULL ? l2->next:NULL;
       } 
        if(carry!=0){
            cur = new ListNode(carry);
            cur->next=head;
            head= cur;
        }
        
        return head;
    }
};