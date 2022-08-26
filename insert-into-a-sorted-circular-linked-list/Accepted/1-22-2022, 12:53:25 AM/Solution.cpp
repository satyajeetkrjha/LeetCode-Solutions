// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            Node* newnode = new Node(insertVal,NULL);
            newnode->next = newnode;
            return newnode;
        }
        Node* prev = head ;
        Node* cur = head->next;
        bool toinsert = false;
        
        do{
            if(insertVal >= prev->val && insertVal <= cur->val){
                toinsert = true;
            }
            // tail is greater than head in this case
            else if((prev->val) >( cur->val)){
                if(insertVal >= prev->val || insertVal <= cur->val){
                    toinsert = true;
                }
            }
            if(toinsert){
                prev->next = new Node(insertVal,cur);
                return head;
            }
            prev = cur ;
            cur = cur->next;
        }while(prev!=head);
        prev->next = new Node(insertVal,cur);
        return head ;
        
        
        
        
    }
};