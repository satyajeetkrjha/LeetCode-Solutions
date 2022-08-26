// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = NULL ;
    Node* tail =NULL;
    
    void dfs(Node* root){
        if(!root) return ;
        dfs(root->left);
        if(head == NULL){
            head = root ;
        }
        else{
            root ->left = tail ;
            tail->right = root ;
        }
        tail = root ;
        dfs(root->right);
    }
    
    
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL ;
        dfs(root);
        head->left = tail ;
        tail->right = head ;
        return head ;
    }
};