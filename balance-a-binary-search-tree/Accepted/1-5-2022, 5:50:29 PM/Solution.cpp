// https://leetcode.com/problems/balance-a-binary-search-tree

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
    
    vector <int> vec;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(vector <int> v ,int left ,int right){
        if(left > right){
            return NULL;
        }
        int mid = (left+right)/2 ;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(v,left ,mid-1);
        root->right = build(v,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int left =0 ;
        int right = vec.size() -1;
        TreeNode* res = build(vec,left ,right);
        return res ;
    }
};