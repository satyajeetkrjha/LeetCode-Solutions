// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    int pre=0;
    TreeNode* inorder(TreeNode* root){
        if( root ==NULL){
            return NULL;
        }
        inorder(root->right);
        pre = root->val =root->val+pre;
        inorder(root->left);
        return root;
        
    }
    TreeNode* convertBST(TreeNode* root) {
       TreeNode* ans = inorder(root);
        return ans ;
    }
};