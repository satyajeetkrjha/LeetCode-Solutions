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
     map <TreeNode* ,TreeNode*> parents ;
      set <TreeNode*> visited ;
    void dfs(TreeNode* cur ,int key){
        if(!cur){
            return ;
        }
        if(cur->left){
            parents[cur->left] = cur;  
        }
        if(cur->right){
            parents[cur->right] = cur ;
           
        }
          dfs(cur->left,key);
          dfs(cur->right,key);
        
        return ;
    }
    
    TreeNode* targetNode(TreeNode* root,int key){
        if(!root){
            return NULL;
        }
        if(root->val == key){
            return root ;
        }
        TreeNode* left = targetNode(root->left ,key);
        TreeNode* right = targetNode(root->right,key);
        if(!left){
            return right;
        }
        return left ;
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
      
       queue<TreeNode*> q ;
       dfs(root,k); 
       TreeNode* source = targetNode(root,k); 
       q.push(source);
        int ans = 0;
       while(!q.empty()){
           int sz = q.size();
           for(int i =0 ;i<sz;i++){
               TreeNode* cur = q.front();
               q.pop();
               visited.insert(cur);
               if(cur->left == NULL  && cur->right == NULL){
                   ans = cur->val ;
                   break;
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
        return ans ;
        
        
    }
};