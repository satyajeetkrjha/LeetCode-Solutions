// https://leetcode.com/problems/symmetric-tree

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
    
    bool dfs(TreeNode* a ,TreeNode* b){
        if(!a && !b){
            return true;
        }
        if(!a || !b)
            return false ;
        
        return a->val == b->val && dfs(a->left,b->right) && dfs(a->right,b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return dfs(root ,root);
    }
};