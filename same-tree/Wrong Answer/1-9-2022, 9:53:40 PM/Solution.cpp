// https://leetcode.com/problems/same-tree

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
    bool dfs(TreeNode* p ,TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p->left && q->left){
            dfs(p->left,q->left);
        }
        
        if(p->val != q->val){
            return false;
        }
        if(p->right && q->right){
             dfs(p->right,q->right);
        }
       
        return true ;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return dfs(p,q);
    }
};