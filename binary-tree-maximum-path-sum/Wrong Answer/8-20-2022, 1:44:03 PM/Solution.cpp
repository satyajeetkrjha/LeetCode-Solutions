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
    int maxpath ;
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int maxleft = max(dfs(root->left),0);
        int maxright = max(dfs(root->right),0);
        maxpath = max(maxpath ,maxleft+maxright+root->val);
        return root->val + max(maxleft,maxright);
    }
    int maxPathSum(TreeNode* root) {
        maxpath =0 ;
        dfs(root);
        return maxpath ;
    }
};