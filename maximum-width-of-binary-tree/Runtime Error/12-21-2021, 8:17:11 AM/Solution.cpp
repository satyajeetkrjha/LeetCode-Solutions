// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        
        queue <pair <TreeNode*,int> > q;
        q.push({root,1});
        
        int ans = 0 ;
        while(!q.empty()){
            int sz = q.size();
            int l = q.front().second;
            int r = l;
            //cout <<"r is "<< r << endl;
            for(int i =0 ;i<sz;i++){
                TreeNode* curr = q.front().first;
                r = q.front().second;
                 q.pop();
                if(curr->left){
                   // cout <<"2*r is "<< (2*r) << endl;
                    q.push({curr->left,2*r});
                } 
                if(curr->right){
                    q.push({curr->right,2*r+1});
                }
                ans = max(ans,r-l+1);    
            }
        }
        return ans ;
        
        
        
    }
};