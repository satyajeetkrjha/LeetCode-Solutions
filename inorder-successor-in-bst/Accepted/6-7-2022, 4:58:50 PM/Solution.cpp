// https://leetcode.com/problems/inorder-successor-in-bst

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        TreeNode* successor = NULL;
        while(root!=NULL){
            if(p->val >= root->val){
                root = root->right ;
            }
            else {
                successor = root ;
                root  = root->left;
            }
        }
        return successor ;
    }
};