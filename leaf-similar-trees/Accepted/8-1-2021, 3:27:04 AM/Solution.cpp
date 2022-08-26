// https://leetcode.com/problems/leaf-similar-trees

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
    
    void dfs (TreeNode* root,vector <int> &v){
         if(!root){
             return;
         }
         dfs(root->left,v);
         if(root->left == NULL && root->right ==NULL){
             v.push_back(root->val);
         }
        dfs(root->right,v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
           vector <int> v1,v2;
            dfs(root1,v1);
            dfs(root2,v2);
        //     for(int i =0 ;i<v1.size();i++){
        //         cout<<v1[i]<<" ";
        //     }
        // cout<<endl;
        //   for(int i =0 ;i<v2.size();i++){
        //       cout<<v2[i]<<" ";
        //   }
        // cout<<endl;
        
           if(v1 == v2){
               return true;
           }
        return false ;
    }
};