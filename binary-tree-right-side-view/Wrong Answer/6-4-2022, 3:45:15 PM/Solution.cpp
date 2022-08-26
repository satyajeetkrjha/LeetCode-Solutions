// https://leetcode.com/problems/binary-tree-right-side-view

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
    
    void dfs(TreeNode* root ,vector <int> &res){
        if(!root) return ;
         res.push_back(root->val);
        if(root->right){
            dfs(root->right,res);
        }
        else if(root->left){
            dfs(root->left,res);
        }
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector <int> res ;
        dfs(root,res);
        return res;
    }
};