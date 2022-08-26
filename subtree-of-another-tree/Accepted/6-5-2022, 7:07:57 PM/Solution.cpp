// https://leetcode.com/problems/subtree-of-another-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    bool isIdentical(TreeNode* a ,TreeNode* b){
        if(a == NULL && b ==NULL)
            return true ;
        if(a ==NULL || b== NULL)
            return false ;
        
        return a->val == b->val && isIdentical(a->left,b->left) &&
            isIdentical(a->right,b->right);
        
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // only one is null 
        if(root ==NULL || subRoot ==NULL){
            return false;
        }
        if(isIdentical(root,subRoot)){
            return true ;
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};