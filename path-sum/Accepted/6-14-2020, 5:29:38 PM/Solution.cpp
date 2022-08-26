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
    bool hasPathSum(TreeNode* root, int sum) {
        TreeNode* temp =root;
        if(temp==NULL)
            return false;
        int subsum=sum-(temp->val);
        if(subsum ==0 && temp->left==NULL && temp->right ==NULL){
            return true;
        } 
         bool ans =hasPathSum(temp->left,subsum) || hasPathSum(temp->right,subsum);
        return ans;
    }
};