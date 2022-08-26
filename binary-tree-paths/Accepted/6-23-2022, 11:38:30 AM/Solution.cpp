// https://leetcode.com/problems/binary-tree-paths

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
    
    vector <string> res ;

    void dfs(TreeNode* root ,string cur){
        if(!root)
            return;
          cur += to_string(root->val);
         if(!root->left && !root->right){
             res.push_back(cur);
         }
        else {
            cur = cur+"->";
            if(root->left){
                  dfs(root->left,cur);
            }
            if(root->right){
                dfs(root->right ,cur);
            }
          
        }
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return res ;
        string cur ="";
        dfs(root,cur);
        return res ;
    }
};