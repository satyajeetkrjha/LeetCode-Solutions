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
    Node* head =NULL;
    Node* tail =NULL;
    
    void dfs(Node* root){
        if(!root) return ;
        dfs(root->left);
        // work on node and this is where we work on node in inorder traversal
        if(!head){
            head = root ; // this is the leftmost node of the tree at bootom and will serve to be our leading node
        }
        else { // we are at a node that is not the depthmost in left .think 
            // this time our root is now 2 so we connect root 2 with tail 1
            root->left = tail ;
            tail->right = root ;
            
        }
        tail = root ; // we made the current root as tail before recursion
        
        
        dfs(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        dfs(root);
        head->left = tail ;
        tail->right = head ;
        return head;
        
        
    }
};