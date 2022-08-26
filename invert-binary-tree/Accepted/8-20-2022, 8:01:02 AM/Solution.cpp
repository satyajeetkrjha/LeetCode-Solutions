// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL ;
        queue <TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                auto temp= cur->right ;
                cur->right = cur->left ;
                cur->left = temp;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return root ;
    }
};