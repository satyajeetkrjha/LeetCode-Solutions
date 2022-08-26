// https://leetcode.com/problems/binary-tree-vertical-order-traversal

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue <pair <TreeNode* ,int>> q;
        map <int ,vector <int> > m;
        vector <vector <int> > res;
        if(!root){
            return res ;
        }
        q.push({root,0});
        while(!q.empty()){
            pair <TreeNode*,int> p = q.front();
            q.pop();
            TreeNode* cur = p.first;
            int val = p.second;
            m[val].push_back(cur->val);
            if(cur->left){
                q.push({cur->left,val-1});
            }
            if(cur->right){
                q.push({cur->right,val+1});
            }
            
        }
        for(auto it: m){
            int value = it.first ;
            vector <int> v= it.second;
            res.push_back(v);
        }
        return res;
    }
};