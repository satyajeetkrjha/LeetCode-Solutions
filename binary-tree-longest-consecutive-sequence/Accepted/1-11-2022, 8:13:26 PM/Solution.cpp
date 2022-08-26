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
    
    int maxval=1;
    void bfs(TreeNode* root){
        if(!root){
            return ;
        }
        queue <pair <TreeNode* ,int> > q;
        q.push({root,1});
        
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                pair<TreeNode*,int> pr = q.front();
                q.pop();
                TreeNode* cur = pr.first ;
                int val = pr.second ;
                if(cur->left){
                    if(cur->left->val - cur->val ==1){
                        maxval = max(maxval ,val+1);
                        q.push({cur->left,val+1});
                    }
                    else{
                        q.push({cur->left,1});
                    }
                }
                if(cur->right){
                    if(cur->right->val - cur->val == 1){
                        maxval = max(maxval ,val+1);
                        q.push({cur->right,val+1});
                    }
                    else{
                        q.push({cur->right,1});
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