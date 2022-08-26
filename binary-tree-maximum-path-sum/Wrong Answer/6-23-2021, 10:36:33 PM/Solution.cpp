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
     int dfs(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int leftsum = dfs(root->left,ans);
        int rightsum = dfs(root->right,ans);
        int totalsum = leftsum +rightsum+root->val;
        ans = max(totalsum,max(leftsum,rightsum));
        return totalsum;
    }
    int maxPathSum(TreeNode* root) {
      int ans =INT_MIN;
       dfs(root,ans);
        return ans ;
    }
};