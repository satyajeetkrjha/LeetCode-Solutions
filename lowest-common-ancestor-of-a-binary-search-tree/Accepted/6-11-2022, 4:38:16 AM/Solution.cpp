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
        
        int pval  = p->val ;
        int qval = q->val; 
        
        TreeNode* cur = root ;
    
        while(cur!=NULL){
            
            int parentval = cur->val ;
            if(pval > parentval && qval > parentval){
                cur= cur->right;
            }
            else if(parentval >pval && parentval > qval){
                cur= cur->left;
            }
            else
                return cur;
        }
        
        
        return NULL;
        
        
        
    }
};