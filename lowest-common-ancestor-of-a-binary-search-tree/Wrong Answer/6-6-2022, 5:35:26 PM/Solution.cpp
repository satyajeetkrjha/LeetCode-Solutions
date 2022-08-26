// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootval = root->val ;
        
        if(p->val > rootval && q->val > rootval){
            lowestCommonAncestor(root->right ,p ,q);
        }
        else if(p->val < rootval && q->val < rootval){
            lowestCommonAncestor(root->left, p, q);
        }
        return root ;
        
    }
};