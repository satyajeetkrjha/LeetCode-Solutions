// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    void dfs(TreeNode* root,vector <int> &v){
        if(root ==NULL){
            return;
        }
        v.push_back(root->val);
        if(root->left){
            dfs(root->left,v);
        }
        if(root->right){
            dfs(root->right,v);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector <int> v;
        dfs(root,v);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        int min_dist =INT_MAX;
        for(int i=1;i<v.size();i++){
           min_dist =min(v[i]-v[i-1],min_dist);
        }
        return min_dist;
    }
};