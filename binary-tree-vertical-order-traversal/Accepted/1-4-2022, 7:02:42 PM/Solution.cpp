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
        queue< pair <TreeNode* ,int> > q;
        map <int ,vector <int> > m;
        vector <vector <int> > res ;
        if(!root){
            return res ;
        }
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                 pair <TreeNode*,int> cur = q.front();
                q.pop();
                TreeNode* n = cur.first ;
                int val = cur.second;
                m[val].push_back(n->val);
                if(n->left){
                    q.push({n->left,val-1});
                }
                if(n->right){
                    q.push({n->right,val+1});
                }
            }
        } 
       for(auto it :m){
           vector <int> v = it.second;
           res.push_back(v);
       } 
        return res ;
        
    }
};