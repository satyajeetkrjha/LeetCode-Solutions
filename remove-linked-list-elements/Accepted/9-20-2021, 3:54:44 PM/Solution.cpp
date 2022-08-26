// https://leetcode.com/problems/remove-linked-list-elements

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
    void printList(ListNode* head){
        while(head!=NULL){
            cout<<head->val <<" ";
            head = head->next;
        }
        cout<<endl;
        
    }
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* sentinal = new ListNode(0);
        sentinal->next = head;
        printList(sentinal->next);
        ListNode* prev = sentinal ;
        ListNode* cur = head ;
        while(cur!=NULL){
            if(cur->val == val){
                prev->next = cur->next;
            }
            else{
                prev = cur;
            }
            cur = cur->next;
        }
        return sentinal->next;
        
        
    }
};