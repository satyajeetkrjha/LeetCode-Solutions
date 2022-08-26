// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
#include <cmath>
class Solution {
public:
    vector<vector<int>>res;
    int sumRootToLeaf(TreeNode* root) {
        if(root ==NULL)
            return 0;
        vector <int> temp;
        dfs(root,temp);
        int result=0;
        for(int i=0;i<res.size();i++){
          result+= binary_conversion(res[i]);
        }
        return result;
    }
    int binary_conversion(vector <int> v){
        int count =0;
        int result =0;
        for(int i=v.size()-1;i>=0;i--){
            int val =pow(2,count);
            val = val*v[i];
            result+=val;
            count++;
        }
        
        cout<<"result "<<result <<endl;
        return result;
    }
    
    void dfs(TreeNode* root,vector <int> temp){
        temp.push_back(root->val);
        if(root->left ==NULL && root->right ==NULL){
            res.push_back(temp);
        }
        else{
            if(root->left){
                dfs(root->left,temp);
            }
            if(root->right){
                dfs(root->right,temp);
            }
        }
    }
};