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
        TreeNode* successor = NULL ;
        
        while(root!=NULL){
            if(p->val >= root->val){
                // discard left subtree 
                root = root ->right;
                if(root)
                cout<<"root value after moving to right is "<<root->val <<endl;
            }
            else{
                successor = root ;
                cout<<"successor possible value is "<<successor->val <<endl;
                root =root->left;
                cout<<"root value after moving to left is "<<root->val <<endl;
            }
        }
        return successor ;
        
    }
};