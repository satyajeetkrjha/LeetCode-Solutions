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
         if(root == NULL){
             return  0;
         }
         int max_left_gain = max(dfs(root->left,ans),0);
         int max_right_gain = max(dfs(root->right,ans),0);
         
         int cur_sum = root->val +max_left_gain+max_right_gain;
         ans = max(ans,cur_sum);
         return root->val +max(max_left_gain,max_right_gain);
     }
    int maxPathSum(TreeNode* root) {
      int ans =INT_MIN;
       dfs(root,ans);
        return ans ;
    }
};