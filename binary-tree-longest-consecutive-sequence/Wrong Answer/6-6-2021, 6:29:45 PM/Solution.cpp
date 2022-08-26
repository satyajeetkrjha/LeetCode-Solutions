// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    int maxval =1;
    void dfs(TreeNode* root,int val){
        if(!root){
            return ;
        }
        
        if (root->left !=NULL &&  root->left->val - root->val == 1){
            val++;
            maxval =max(maxval,val);
            cout <<"root->left val is "<<root->left->val<<endl;
            cout <<"root->val is "<<root->val <<endl;
            cout <<"val is "<<val <<endl;
            dfs(root->left,val);
        
        }
        else{
            dfs(root->left,val);
        }
         
        if(root->right !=NULL && root->right->val - root->val ==1){
            val ++;
            maxval =max(maxval,val);
            cout <<"root->right val is "<<root->right->val<<endl;
            cout <<"root->val is "<<root->val <<endl;
            cout <<"val is "<<val <<endl;
            dfs(root->right,val);
        }
        else{
           dfs(root->right,val);   
        }
      
        
    }
    int longestConsecutive(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root,1);
        return maxval;
        
    }
};