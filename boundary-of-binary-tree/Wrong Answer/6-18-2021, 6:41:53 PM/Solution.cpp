// https://leetcode.com/problems/boundary-of-binary-tree

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
    void LeftTree(TreeNode* root , vector <int> &ans){
        if(!root){
            return;
        }
        if(root->left){
            ans.push_back(root->val);
            LeftTree(root->left,ans);
        }
       else if(root->right){
            ans.push_back(root->val);
            LeftTree(root->right,ans);
        }
    }
    void Leaf(TreeNode* root, vector <int> &ans){
        if(!root){
            return ;
        }
        Leaf(root->left,ans);
        if(root->left ==NULL && root->right ==NULL){
            ans.push_back(root->val);
        }
        Leaf(root->right,ans);
    }
    void RightTree(TreeNode* root , vector <int> &ans){
        if(!root){
            return ;
        }
        if(root->right){
            RightTree(root->right,ans);
            ans.push_back(root->val);
        }
        else if(root->left){
            RightTree(root->left,ans);
            ans.push_back(root->val);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector <int> ans ;
        if(!root){
            return ans;
        }
        ans.push_back(root->val);
        LeftTree(root->left,ans);
        Leaf(root,ans);
        RightTree(root->right,ans);
        return ans ;
        
    }
};