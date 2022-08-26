// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    int pre =0;
    TreeNode* reverseinorder(TreeNode* root){
        if(root ==NULL){
            return NULL;
        }
        reverseinorder(root->right);
        pre=root->val = pre+root->val;
        reverseinorder(root->left);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* ans = reverseinorder(root);
        return ans ;
    }
};