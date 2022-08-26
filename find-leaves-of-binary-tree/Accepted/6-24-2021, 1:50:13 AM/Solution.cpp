// https://leetcode.com/problems/find-leaves-of-binary-tree

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
    int dfs(TreeNode* root, map <int ,vector <int>>&m){
        if(root ==NULL){
            return 0;
        }
        int leftheight = dfs(root->left,m);
        int rightheight = dfs(root->right,m);
        int height = max(leftheight,rightheight)+1;
        m[height].push_back(root->val);
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
       map <int ,vector <int> > m;
       vector <vector <int> > res;
        dfs(root,m);
        map <int ,vector <int> > ::iterator it ;
        for(it = m.begin();it!=m.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};