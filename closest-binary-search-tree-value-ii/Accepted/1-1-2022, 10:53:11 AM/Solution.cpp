// https://leetcode.com/problems/closest-binary-search-tree-value-ii

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
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        dfs(root);
        int left = 0 ;
        int n = vec.size();
        int right = n-k;
        
        while (left<right){
            int mid = (right+left)/2;
            if(target- vec[mid] > vec[mid+k] -target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        vector <int> res ;
        for(int i= left ;i<left+k;i++){
            res.push_back(vec[i]);
        }
        
        return res;
    }
};