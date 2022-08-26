// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) 
            return false ;
      //  cout <<"Initial target sum is "<<targetSum << endl;
       // cout <<"root->val is "<<root->val <<endl;
        targetSum -= root->val ;
       // cout <<"targetSum is" << targetSum << endl;
        
        if(!root->left && !root->right && targetSum == 0){
            return true;
        }
      return hasPathSum(root->left,targetSum ) || hasPathSum(root->right,targetSum);
    }
};