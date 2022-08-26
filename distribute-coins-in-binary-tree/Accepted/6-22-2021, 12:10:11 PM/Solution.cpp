// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    int res;
    pair <int, int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        int n =1; int coin = root->val ;
        auto [leftcount ,leftcoins ] = dfs(root->left);
        
        res += abs(leftcount -leftcoins);
        n+=leftcount;
        coin+=leftcoins;
        
        auto [rightcount ,rightcoins] = dfs(root->right);
        res += abs(rightcount - rightcoins);
        n+=rightcount;
        coin +=rightcoins;
        
        return {n,coin};
        
    }
    int distributeCoins(TreeNode* root) {
       res =0;
        dfs(root);
        return res;
    }
};