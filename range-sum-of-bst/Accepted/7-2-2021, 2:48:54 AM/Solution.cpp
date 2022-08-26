// https://leetcode.com/problems/range-sum-of-bst

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
    void dfs(TreeNode * root ,int &sum ,int low ,int high){
        if(!root) 
            return ;
        dfs(root->left,sum,low,high);
        dfs(root->right,sum ,low,high);
        if(root !=NULL && root->val >=low && root->val <=high){
            sum+=root->val;
        }
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0 ;
        dfs(root ,sum,low,high);;
        return sum;
    }
};