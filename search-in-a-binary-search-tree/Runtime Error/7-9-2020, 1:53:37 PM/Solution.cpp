// https://leetcode.com/problems/search-in-a-binary-search-tree

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
    TreeNode* dfs(TreeNode* root,int val){
        cout<<"root->val is "<<root->val<<endl;
        if(root->val == val){
            return root;
        }
        if(root->val <=val ){
            dfs(root=root->right,val);
        }
        if(val< root->val){
            
            dfs(root=root->left,val);
        }
        return root;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return root;
       TreeNode* ans = dfs(root,val);
        return ans;
    }
};