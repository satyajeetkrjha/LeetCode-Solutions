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
     
        if(!head){
            Node * temp = new Node(insertVal,NULL);
            temp->next = temp;
            return temp;
        }
        Node* prev = head ;
        Node * cur = head->next ;
        bool toinsert = false;
        
        
        do{
            if(insertVal >= prev->val && insertVal<= cur->val){
                toinsert = true;
            }
            else if(prev->val > cur->val){
               if(insertVal >= prev->val || insertVal <= cur->val){
                   toinsert = true;
               }
            }
            if(toinsert){
                prev->next = new Node(insertVal,cur);
                return head ;
                
            }
            prev = cur ;
            cur = cur->next; 
        }while(prev!=cur);
        prev->next = new Node(insertVal,cur);
        return head;
        
        
    }
};