// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
       
        queue<TreeNode* >q;
        q.push(root);
        bool xfound =false;
        bool yfound =false;
        while(!q.empty()){
            
            int sz = q.size();
            cout<<"Queue Processing"<<endl;
            cout<<"Queue size is "<<sz<<endl;
            for(int i=0;i<sz;i++){
                TreeNode* cur =q .front();
                q.pop();
                // you are at current node and current node has x and y as child nodes
                if(cur->left && cur->left->val == x && cur->right && cur->right->val ==y){
                    return false;
                }
                 if(cur->left && cur->left->val == y && cur->right && cur->right->val ==x){
                    return false;
                }
                // if ur current node's value is either x or y mark xfound and yfound to be true
                cout<<"cur->val is "<<cur->val<<endl;
                if( cur->val==x){
                    xfound =true;
                }
                if(cur->val==y){
                    yfound =true;
                }
                if(cur->left)
                q.push(cur->left);
                
                if(cur->right)
                q.push(cur->right);
                
                
            }
            // after every level that we do in bfs we check for things 
        if(xfound && yfound )
            return true;
        if(xfound || yfound)
            return false;
        }
        
        return false;
    }
};