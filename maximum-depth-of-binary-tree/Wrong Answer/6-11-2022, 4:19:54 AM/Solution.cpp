// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxlevel =INT_MIN;
    
    void dfs(TreeNode* root ,int level){
        if(!root)
            return;
    
        maxlevel = max(maxlevel,level);
        dfs(root->left,level++);
        dfs(root->right,level++);
            
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return maxlevel;
    }
};