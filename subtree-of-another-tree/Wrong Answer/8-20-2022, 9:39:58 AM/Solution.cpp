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
    
    bool isIdentical(TreeNode* p,TreeNode* q){
        if(!p && !q)
            return true;
        if(!p or !q)
            return false;
        if(p->val != q->val)
            return false ;
        return isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
    }
    
    
    
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true ;
        if(!root || !subRoot)
            return false ;
        return isIdentical(root->left ,subRoot) || isIdentical(root->right,subRoot);
    }
};