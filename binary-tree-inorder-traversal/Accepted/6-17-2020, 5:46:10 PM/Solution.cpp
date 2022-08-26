// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        stack <TreeNode*> s;
        bool done = false;
        TreeNode* cur =root;
        while(cur!=NULL || !s.empty() ){ 
            while(cur!=NULL){
                s.push(cur);
                cur= cur->left;
            }
            cur =s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
            
            
        }
        return res;
    }
};