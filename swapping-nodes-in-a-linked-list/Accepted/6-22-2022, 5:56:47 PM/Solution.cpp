// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 =head ;
        ListNode* ptr2 ;
        ListNode* kth ;
        
        for(int i =1 ;i<k;i++){
            ptr1 = ptr1->next;
        }
        
        cout <<ptr1->val << endl;
        
        
        // now ptr1 is pointing to the kth node in linked list
        // set kth node to point to this node
        kth = ptr1;
        ptr1 = ptr1->next ;
        ptr2 = head ; // now ptr2 is k nodes behind ptr1
        while(ptr1!=NULL){
            ptr1 = ptr1->next ;
            ptr2=  ptr2->next;
        }
        
        // ptr1 reached end and ptr2 is still kth len behind it 
        // means ptr2 is at n-k place or k from behind and this is what we want
        swap(ptr2->val,kth->val);
        return head ;
    }
};