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
    
    void LeftMost(TreeNode* root ,vector <int> &res){
        if(!root) return ;
        
        if(root->left){
            res.push_back(root->val);
            LeftMost(root->left,res);
        }
        
        else if(root->right){
            res.push_back(root->val);
            LeftMost(root->right,res);
        }
    }
    
    void Leaf(TreeNode* root,vector <int> &res){
        if(!root) return ;
        
        if(root->left){
            Leaf(root->left,res);
        }
        
        if(!root->left && !root->right){
            res.push_back(root->val);
        }
        
        if(root->right){
            Leaf(root->right,res);
        }
        
        
    }
    void RightMost(TreeNode* root ,vector <int> &res){
        
        if(!root) return;
        
        if(root->right){
             RightMost(root->right,res);
             res.push_back(root->val);
           
        }
        else if(root->left){
            RightMost(root->left,res);
            res.push_back(root->val);
            
        }
        
    }
    
    
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector <int> res ;
        
        if(!root){
            return res ;
        }
        
        res.push_back(root->val);
        
        LeftMost(root->left,res);
        Leaf(root,res);
        RightMost(root->right,res);
        
        return res ;
        
        
    }
};