// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameter ;
    int dfs(TreeNode* root){
        if(!root)
            return 0 ;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        diameter  = max(diameter ,lh+rh);
        return max(lh,rh)+1;
    }
    
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0 ;
        diameter =0 ;
        dfs(root);
        return diameter ;
    }
};