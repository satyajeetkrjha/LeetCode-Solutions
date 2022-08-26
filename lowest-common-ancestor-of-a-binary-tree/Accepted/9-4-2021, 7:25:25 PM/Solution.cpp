// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      stack <TreeNode*> s ;
      map <TreeNode* ,TreeNode*> parent ;
      s.push(root);
      parent[root]=NULL;
      while(parent.find(p)== parent.end() || parent.find(q)== parent.end()){
          TreeNode* cur = s.top();
          s.pop();
          if(cur->left!=NULL){
              s.push(cur->left);
              parent[cur->left]= cur;
          }
          if(cur->right !=NULL){
              s.push(cur->right);
              parent[cur->right]=cur; 
          } 
      }
        set <TreeNode*> ancestors;
        while(p!=NULL){
            ancestors.insert(p);
            p = parent[p];
        }
        
        while(ancestors.count(q) == 0){
             q = parent[q];
        }
        return q;
            
    }
};