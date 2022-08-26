// https://leetcode.com/problems/count-univalue-subtrees

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
    int ans = 0;
    pair <int,int> dfs(TreeNode* root){
        if(!root){
            return {INT_MAX,INT_MIN};
        }
        
      auto [leftmin,leftmax] = dfs(root->left);
      auto [rightmin,rightmax] = dfs(root->right);
        
     leftmin = min(leftmin,root->val);
     leftmax = max(leftmax,root->val);
        
     rightmin = min (rightmin,root->val);
     rightmax = max (rightmax ,root->val);
     
      int totalmin = min(leftmin,rightmin);
       int totalmax = max(leftmax,rightmax);
        if(totalmin ==totalmax){
            ans++;
        }
        cout<<"totalmin "<<totalmin<<endl;
        cout<<"totalmax is "<<totalmax <<endl;
        return {totalmin,totalmax};
        
    }
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};