// https://leetcode.com/problems/increasing-order-search-tree

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
    void inorder(TreeNode* root ,vector <TreeNode*> &v){
        if(root == NULL)
            return ;
        inorder(root->left,v);
        v.push_back(root); // don't push the value of root and instead push the root 
        inorder(root->right,v);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        // create a vector of TreeNodes 
        vector <TreeNode*> v;
        inorder(root,v);
        
        // we now have all nodes of the tree in increasing order 
        for(int i =0 ;i<v.size()-1;i++){
            v[i]->left= NULL;
            v[i]->right = v[i+1]; // at right side ,u put the entire node 
        }
        v[v.size()-1]->right = NULL;
        v[v.size()-1]->left =NULL;
        return v[0];
        
        
    }
};