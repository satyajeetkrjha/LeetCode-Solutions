// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int val;
    int ans ;
    void inorder(TreeNode *root,int k){
        if(!root)
            return ;
        inorder(root->left, k);
        val ++;
        if(val == k){
            ans = root->val;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        val =0;
        inorder(root,k);
        return ans ;
    }
};