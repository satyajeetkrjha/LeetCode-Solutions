// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    int maxval =1;
    void bfs(TreeNode* root){
        queue <pair <TreeNode*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            int sz =q.size();
            for(int i=0;i<sz;i++){
              pair<TreeNode*,int> p =q.front();
                q.pop();
            TreeNode* cur = p.first;
            int val =p.second;
               
            if(cur->left){
                if(cur->left->val -cur->val ==1){
                    maxval =max(maxval,p.second+1);
                    q.push(make_pair(cur->left,p.second+1));
                }
                else{
                    q.push(make_pair(cur->left,1));
                }
             } 
             if(cur->right){
                 if(cur->right->val - cur->val == 1){
                     maxval=max(maxval,p.second+1);
                     q.push(make_pair(cur->right,p.second+1));
                 }
                 else{
                      q.push(make_pair(cur->right,1));
                 }
             }              
            
        }
      }
    }
                           


                    
    
    int longestConsecutive(TreeNode* root) {
        if(!root){
            return 0;
        }
        bfs(root);
        return maxval;
        
    }
};