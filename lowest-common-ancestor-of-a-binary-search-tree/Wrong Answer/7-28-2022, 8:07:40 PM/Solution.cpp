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
    
        int pVal = p->val ;
        int qVal = q->val ;
        TreeNode* cur = root ;
        while(cur!=NULL){
           int parentVal = cur->val ;
           if(pVal > parentVal && qVal > parentVal){
               cur = cur->right ;
           }
            else if(pVal <parentVal && qVal <parentVal){
                cur = cur->left;
            }
            return cur;
        }
        return NULL ;
    }
};