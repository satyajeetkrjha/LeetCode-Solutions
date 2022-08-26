// https://leetcode.com/problems/diameter-of-binary-tree

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
    
    
    int diameter ;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0 ;
        depth(root);
        return diameter ;
    }
    
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int ld = depth(root->left);
        int rd = depth(root->right);
        diameter = max(diameter ,ld+rd);
        return max(ld,rd)+1;
    }
};