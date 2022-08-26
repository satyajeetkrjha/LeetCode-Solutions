// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    set <int> s;
    void dfs (TreeNode* root){
        if(!root)
            return ;
        dfs(root->left);
        s.insert(root->val);
        if(s.size() ==3){
            return ;
        }
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(s.size() ==1)
            return -1 ;
        int c =0;
        int ans ;
        for(auto it :s){
            c++;
            if( c== 2){
                ans = it ;
            }
        }
        return ans;
    }
};