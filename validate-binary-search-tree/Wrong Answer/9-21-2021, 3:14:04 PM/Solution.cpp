// https://leetcode.com/problems/validate-binary-search-tree

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
    bool Validate(TreeNode* root ,int low ,int high){
        if(root ==NULL) return true ;
        if((low!=NULL && root->val <= low) || (high!=NULL && root->val >= high)){
            return false;
        }
        return 
            Validate(root->left,low,root->val) && Validate(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
      return Validate(root ,NULL ,NULL);
    }
};