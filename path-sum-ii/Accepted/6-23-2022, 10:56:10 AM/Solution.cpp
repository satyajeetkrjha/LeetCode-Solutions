// https://leetcode.com/problems/path-sum-ii

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
    
    vector <vector<int> > res ;
    
    vector <int> v;
    void dfs(TreeNode* root,int pathsum,int targetSum){
        if(!root)
            return ;
        pathsum+= root->val;
        v.push_back(root->val);
        if(!root->left && !root->right && pathsum == targetSum){
            res.push_back(v);
         }
        if(root->left){
            dfs(root->left,pathsum,targetSum);
        }
        if(root->right){
            dfs(root->right,pathsum,targetSum);
        }
        if(v.size()>0){
            v.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root ==NULL)
            return res ;
        int pathsum =0 ;
        dfs(root,pathsum ,targetSum);
        return res ;
    }
};