// https://leetcode.com/problems/count-univalue-subtrees

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
    int ans = 0;
    pair <int,int> dfs(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        auto[leftsum,leftcount] = dfs(root->left);
        auto [rightsum,rightcount] = dfs(root->right);
        int totalsum = leftsum +rightsum +root->val;
        int nodecount = leftcount +rightcount+1;
        cout<<"totalsum is "<<totalsum<<endl;
        cout<<"nodecount is "<<nodecount <<endl;
        if( root->val == (totalsum/nodecount) && (totalsum%nodecount ==0)){
            ans++;
        }
        return {totalsum,nodecount};
    }
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};