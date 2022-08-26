// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    map <int ,int> m;
    int maxVal = -1;
    void dfs(TreeNode* root){
        if(!root){
            return ;
        }
        dfs(root->left);
        m[root->val]++;
        maxVal = max(maxVal ,m[root->val]);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
       
        
        /*
        for(auto it :m){
            if(it.second > maxVal){
                maxVal = it.second;
            }
        }
        */
        
        cout <<"maxVal is "<< maxVal << endl;
        vector <int> res ;
        
        for(auto it : m){
            if(it.second == maxVal){
                res.push_back(it.first);
            }
        }
        return res ;
        
    }
};