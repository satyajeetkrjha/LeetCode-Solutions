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
 int diamter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diamter = 0;
        longestpath(root);
        return diamter;
    }
    int longestpath(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int leftpath = longestpath(root->left);
        int rightpath = longestpath(root->right);
        diamter = max(diamter,leftpath+rightpath);
        return max(leftpath,rightpath)+1;
    }
};