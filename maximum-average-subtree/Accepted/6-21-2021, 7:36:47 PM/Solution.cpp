// https://leetcode.com/problems/maximum-average-subtree

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
    pair <int ,int > dfs(TreeNode* root ,double &result){
        if(!root){
            return {0,0};
        }
        auto[leftsum,leftcount] = dfs(root->left,result);
        auto[rightsum,rightcount] = dfs(root->right,result);
        double totalsum = leftsum+rightsum+root->val;
        int totalnodecount = leftcount+rightcount+1;
        result = max(result ,(totalsum/totalnodecount));
        return {totalsum,totalnodecount};
        
        
        
        
    }
    double maximumAverageSubtree(TreeNode* root) {
      double result = INT_MIN;
      dfs(root,result);
      return result ;
    }
};