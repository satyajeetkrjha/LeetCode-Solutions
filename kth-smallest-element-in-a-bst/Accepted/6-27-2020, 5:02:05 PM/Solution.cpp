// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode*> s;
      TreeNode* cur= root;
        int count =0;
        int ans ;
      while(cur!=NULL || !s.empty()){
          while(cur!=NULL){
              s.push(cur);
              cur = cur->left;
          }
          cur =s.top();
          s.pop();
          count++;
          if(count==k){
             ans=cur->val;
              break;
          }
          cur = cur->right;   
      }
        return ans;
    }
};