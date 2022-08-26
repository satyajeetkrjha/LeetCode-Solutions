// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int findBottomLeftValue(TreeNode* root) {
     queue <TreeNode*> q;
     q.push(root);
     TreeNode* result =NULL;
     while(!q.empty()){
         TreeNode* cur = q.front();
         q.pop();
         if(cur->left){ // if current node has a left node and that left node is a leaf node
             if(!cur->left->left && !cur->left->right){
                 result = cur->left;
             }
             q.push(cur->left);
             
             
         }
         if(cur->right){
             q.push(cur->right);
         }
     }
        return result->val ;
    }
};