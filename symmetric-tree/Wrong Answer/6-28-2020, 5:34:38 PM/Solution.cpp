// https://leetcode.com/problems/symmetric-tree

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
    bool symmetric( TreeNode* nodeA, TreeNode* nodeB){
        if(nodeA == NULL && nodeB ==NULL){
            return true;
        }
        if(nodeA == NULL || nodeB ==NULL){
            return false;
        }
        if(nodeA->val ==nodeB ->val){
            if(symmetric(nodeA->left,nodeB->left) && symmetric(nodeB->right,nodeB->right)){
                return true;
                
            }
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        bool ans =true;
        ans = symmetric(root,root);
        return ans;
    }
};