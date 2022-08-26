// https://leetcode.com/problems/invert-binary-tree

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
    
    void dfs(TreeNode* root){
        if(!root)
            return ;
        dfs(root->left);
        dfs(root->right);
        TreeNode* temp = root->right ;
        root->right= root->left;
        root->left = temp ;
    }
    
    TreeNode* invertTree(TreeNode* root) {
      dfs(root);
        return root ;
    }
};