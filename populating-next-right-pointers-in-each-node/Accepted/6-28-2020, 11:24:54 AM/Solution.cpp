// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root==NULL)
           return root;
       int no=1; // to indicate number of nodes at a level
       queue <Node*> q;
       q.push(root);
       while(!q.empty()){
           int sz= q.size();
           for(int i=0;i<sz;i++){
               Node* cur =q.front();
               q.pop();
               Node* next = nullptr;
               if(i == no-1){
                   cur->next=next;
               }
               else{   
                    cout<<"q.size is "<<q.size()<<endl;
                    next =q.front();
                    cur->next =next;
               }
               if(cur->left)
                   q.push(cur->left);
               if(cur->right)    
                   q.push(cur->right);
           }
           no=no*2; // because it is complete so nodes will be double of current number of nodes
       }
        return root;
    }
};