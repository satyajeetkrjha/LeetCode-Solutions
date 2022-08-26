// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    TreeNode* bstToGst(TreeNode* root) {
        int pre =0;
        TreeNode* cur = root;
        stack <TreeNode*> s;
        while(!s.empty() ||  cur!=NULL){
            if(cur !=NULL){
                s.push(cur);
                cur = cur->right;
            }
            else {
                cur =s.top();
                s.pop();
                cur->val =pre=pre+cur->val;
                cur = cur->left;
                
            }
        }
        return root;
    }
};