// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
 int val =1;   
public:
    
    void dfs(TreeNode* root){
        if(!root){
            return ;
        }
        if (root->left !=NULL &&  root->left->val - root->val == 1){
            val++;
        }
         dfs(root->left);
        if(root->right !=NULL && root->right->val - root->val ==1){
            val ++;
        }
        dfs(root->right);
    }
    int longestConsecutive(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root);
        return val;
        
    }
};