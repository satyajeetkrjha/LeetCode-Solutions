// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        if(root==NULL)
            return sum;
        queue <TreeNode* >q ;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left && cur->left->left== NULL && cur->left->right==NULL)
                sum += curr->left->val;
            if(cur->left){
            
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return sum;
    }
};