// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii

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
     int ans;
    int longestConsecutive(TreeNode* root) {
        ans =0;
        dfs(root);
        return ans ;
    }
    pair <int ,int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        
        int inc = 1;
        int dec = 1 ;
        
        
        if(root->left!=NULL){
            pair <int,int> left = dfs(root->left);
            if(root->val == root->left->val +1){
                dec = left.second+1;
            }
            else if(root->val == root->left->val-1){
                inc = left.first+1;
            }
        }
        
        if(root->right!=NULL){
            pair <int ,int> right = dfs(root->right);
            if(root->val == root->right->val+1){
                dec = max(dec,right.second+1);
            }
            else if (root->val == root->right->val -1){
                inc = max(inc,right.first +1);
            }
        }
        ans = max(ans ,inc+dec-1);
        
        return {inc,dec};
        
        
    }
};