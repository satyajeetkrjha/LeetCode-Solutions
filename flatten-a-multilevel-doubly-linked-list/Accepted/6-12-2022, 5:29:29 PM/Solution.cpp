// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head ;
        Node* tail = head ;
        stack <Node*> st ;
        
        while(cur!=NULL){
            if(cur->child!=NULL){
                Node* child = cur->child ;
                if(cur->next!=NULL){
                    st.push(cur->next);
                    cur->next->prev=NULL;
                }
                cur->next = child ;
                child->prev = cur;
                cur->child =NULL;
            }
            tail = cur ;
            cur = cur->next;
        }
        
        while(!st.empty()){
           auto cur= st.top();st.pop();
            tail->next = cur;
            cur->prev = tail ;
            while(cur!=NULL){
                tail = cur ;
                cur = cur->next;
            }
        }
        return head ;
        
    }
};