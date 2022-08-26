// https://leetcode.com/problems/correct-a-binary-tree

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
   
    TreeNode* correctBinaryTree(TreeNode* root) {
        set<TreeNode*> seen;
queue<TreeNode*> bfsq;

bfsq.push(root);
seen.insert(root);

while(!bfsq.empty()) {
  auto cur = bfsq.front();
    bfsq.pop();
  if(cur->right) {
    if(seen.count(cur->right->right)) {cur->right = NULL; return root;}
    bfsq.push(cur->right); 
      seen.insert(cur->right);
      
  }
  if(cur->left) {
    if(seen.count(cur->left->right)) {cur->left = NULL; return root;}
    bfsq.push(cur->left); seen.insert(cur->left);
  }
}
return root;
        
    }
};