// https://leetcode.com/problems/closest-leaf-in-a-binary-tree

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
    void dfs(TreeNode* root, map <TreeNode*,TreeNode*> parents){
        if(!root){
            return ;
        }
        if(root->left){
            parents[root->left]=root;
        }
        if(root->right){
            parents[root->right]=root;
        }
        dfs(root->left,parents);
        dfs(root->right,parents);
        return;
    }
    TreeNode* targetNode(TreeNode* root,int k){
        TreeNode* ans ;
        if(!root)
            return NULL;
        targetNode(root->left,k);
        if(root->val == k){
            ans = root;
        }
        targetNode(root->right,k);
        return ans;
    }
    int findClosestLeaf(TreeNode* root, int k) {
      map <TreeNode*,TreeNode*> parents;
      set <TreeNode*> visited;
      dfs(root,parents);
      queue <TreeNode*> q;
      TreeNode* target = targetNode(root,k);
      cout<<"target->val is "<<target->val<<endl;  
      q.push(target);
        int ans =-1;
      while(!q.empty()){
          int sz = q.size();
          for(int i=0;i<sz;i++){
              TreeNode* cur = q.front();
              q.pop();
              visited.insert(cur);
              if(cur->left == NULL && cur->right == NULL){
                  ans = cur->val;
                  return ans;
              }
              if(parents[cur] && visited.find(parents[cur]) == visited.end()){
                  q.push(parents[cur]);
              }
              if(cur->left && visited.find(cur->left) == visited.end()){
                  q.push(cur->left);
              }
              if(cur->right && visited.find(cur->right) == visited.end()){
                  q.push(cur->right);
              }
              
          }
      }   
        return ans;
        
        
    }
};