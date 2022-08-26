// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
         queue <TreeNode*> q;
         TreeNode* temp =root;
         q.push(temp);
         int sum =0;
         while(!q.empty()){
              int sz = q.size();
             sum =0;
              for(int i=0;i<sz;i++){
                  TreeNode* cur =q.front();
                  q.pop();
                  sum+= cur->val;
                  if(cur->left)
                      q.push(cur->left);
                  if(cur->right)
                      q.push(cur->right);
                  
              }
         }
        cout<<"sum is "<<sum<<endl;
        return sum;
    }
};