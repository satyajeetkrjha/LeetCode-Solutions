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
        int pval = p->val;
        int qval = q->val;
        if(pval > rootval && qval > rootval){
          lowestCommonAncestor(root->right ,p ,q);
        }
        else if(pval < rootval && qval < rootval){
          lowestCommonAncestor(root->left, p, q);
        }
        cout <<"root->val is"<<root->val << endl;
        return root ;
        
    }
};