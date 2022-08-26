// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> res;
        stack<TreeNode*> s;
        if(root == NULL)
            return res;
        TreeNode* cur =root;
        s.push(cur);
        while(!s.empty()){
            cur =s.top();
            s.pop();
            res.push_back(cur->val);
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};