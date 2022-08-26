// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector <vector <int> > res;
        if(root==NULL)
            return res;
      queue <TreeNode*> q;
      q.push(root);
      TreeNode* cur;
      while(!q.empty()){
          int sz= q.size();
          vector <int> temp;
          for(int i=0;i<sz;i++){
              cur =q.front();
              q.pop();
              temp.push_back(cur->val);
              if(cur->left)
                  q.push(cur->left);
              if(cur->right)
                  q.push(cur->right);
              
          }
          res.push_back(temp);
      }
        reverse(res.begin(),res.end());
        return res;
        
    }
};