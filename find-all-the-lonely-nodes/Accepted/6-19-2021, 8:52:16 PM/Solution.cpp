// https://leetcode.com/problems/find-all-the-lonely-nodes

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
    void dfs(TreeNode* root ,vector <int> &ans){
        if(!root){
            return ;
        }
        dfs(root->left,ans);
        if ((root->left && !root->right) || (root->right && !root->left)){
            if(root->left){
                ans.push_back(root->left->val);
            }
            if(root->right){
                ans.push_back(root->right->val);
            }
        }
        dfs(root->right,ans);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
       vector <int> ans ;
       if(!root){
           return ans;
       } 
        dfs(root,ans);
        return ans;
    }
};