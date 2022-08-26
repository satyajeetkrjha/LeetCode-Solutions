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
   vector <int> res ;
    void dfs(TreeNode* root, int low, int high){
        if(!root)
            return;
        dfs(root->left,low,high);
        if(root->val >= low && root->val <= high){
            res.push_back(root->val);
        }
        dfs(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
         dfs(root,low ,high);
         int sum =0 ;
        for(auto &it:res){
            sum += it;
        }
        return sum ;
    }
};