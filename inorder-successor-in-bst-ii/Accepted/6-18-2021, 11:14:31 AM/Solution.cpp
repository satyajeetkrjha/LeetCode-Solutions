// https://leetcode.com/problems/inorder-successor-in-bst-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // case 1 when successor is in the downside tree
        if(node ->right){
            // first go to right 
            node = node ->right ;
            // now go as left as you can 
            while(node ->left){
                node = node ->left;
            }
            return node ;
            
        }
        // case 2 find the first ancestor which is a left child
        
        //keep going up as long as u are the right child .when u can't gp up because u are no more the right child ,return the parent
        while( node ->parent && node == node ->parent->right){
            node = node ->parent;
        }
        return node->parent;
    }
};