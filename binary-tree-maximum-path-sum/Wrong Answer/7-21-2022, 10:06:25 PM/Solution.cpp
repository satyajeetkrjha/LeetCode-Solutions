// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxsum ;
    
    int  dfs(TreeNode* root){
        if(!root)
            return 0 ;
        
        int leftsum = dfs(root->left);
        int rightsum = dfs(root->right);
        int pathsum = leftsum +rightsum +root->val;
        maxsum =max(maxsum ,pathsum);
        return root->val + max(leftsum ,rightsum);
        
    }
    

    int maxPathSum(TreeNode* root) {
        maxsum =0 ;
        dfs(root);
        return maxsum ;
    }
};