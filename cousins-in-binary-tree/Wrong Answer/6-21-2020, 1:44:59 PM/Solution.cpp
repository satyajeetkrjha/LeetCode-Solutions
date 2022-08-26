// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
       
        queue<TreeNode* >q;
        q.push(root);
        bool xfound =false;
        bool yfound =false;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* cur =q .front();
                q.pop();
                if(cur->left && cur->left->val == x && cur->right && cur->right->val ==y){
                    return false;
                }
                 if(cur->left && cur->left->val == y && cur->right && cur->right->val ==x){
                    return false;
                }
                if(cur->left && cur->left->val==x){
                    xfound =true;
                }
                if(cur->right && cur->right->val==y){
                    yfound =true;
                }
                if(cur->left)
                q.push(cur->left);
                
                if(cur->right)
                q.push(cur->right);
                
                
            }
        if(xfound && yfound )
            return true;
        if(xfound || yfound)
            return false;
        }
        
        return false;
    }
};