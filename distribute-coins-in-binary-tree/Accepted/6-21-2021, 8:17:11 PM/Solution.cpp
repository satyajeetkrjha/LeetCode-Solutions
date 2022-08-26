// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    int steps =0;
    int dfs(TreeNode *root){
        if(!root){
            return 0;
        }
        int left= dfs(root->left); // defecit or excess in left
        int right = dfs(root->right); // defecit or excess in right 
        steps += abs(left)+abs(right); 
        return left+right +(root->val -1);
        
        
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps ;
    }
};