// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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
    
    TreeNode* lca(TreeNode * root ,TreeNode* p ,TreeNode* q){
        if(!root || root == p || root == q)
            return root ;
        TreeNode* left = lca(root->left ,p,q);
        TreeNode* right = lca(root->right,p,q);
        
        return !left? right: !right ? left:root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root || !root->left || !root->right){
            return root ;
        }
        TreeNode* leftmost = NULL;
        TreeNode* rightmost = NULL;
        
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if( i == 0) leftmost = curr ;
                if(i == sz-1) rightmost = curr ;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }   
        }
        
        return lca (root ,leftmost ,rightmost);
        
        
    }
};