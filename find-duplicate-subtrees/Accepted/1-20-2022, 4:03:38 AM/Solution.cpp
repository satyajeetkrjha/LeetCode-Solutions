// https://leetcode.com/problems/find-duplicate-subtrees

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
    
    string dfs(TreeNode* root ,map <string ,int> &m ,vector <TreeNode*>&res){
        if(!root)
            return "" ;
        string s =to_string(root->val)+","+dfs(root->left,m,res)+","+dfs(root->right,m,res);
     //   cout <<"string s before updating map is "<< s << endl;
        if(m[s]++ ==1){
            res.push_back(root);
        }
       // cout <<"Before return string s is "<< s << endl;
        return s ;
        
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map <string ,int> m ;
        vector<TreeNode*> res ;
        dfs(root,m,res);
        return res ;
    }
    
};