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
    bool flag = false;
    void inorder(TreeNode* root,int val){
        if(!root)
            return ;
        inorder(root->left,val);
        
        if(root->val >= val){
            val = root->val;
        }
        else{
            flag = true ;
            return ;
        }
        inorder(root->right,val);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root,INT_MIN);
        return !flag ;
    }
};