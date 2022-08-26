// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root ==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans =INT_MIN;
        while(!q.empty()){
            int sz = q.size();
            ans = max(ans,sz);
            for(int i=0;i<sz;i++){
                TreeNode* cur =q.front();
                q.pop();
                if(cur ==NULL){
                    // don't do anything
                }
                else if(!cur->left  && !cur->right){
                    // don't do anything 
                }
                else {
                        q.push(cur->left);
                        q.push(cur->right);
                }
            }
        }
        return ans;
    }
};