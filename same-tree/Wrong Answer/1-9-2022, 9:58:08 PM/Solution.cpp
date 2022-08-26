// https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       queue <TreeNode*> q1;
        queue <TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        vector <int> v1,v2;
        while(!q1.empty()){
            int sz = q1.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q1.front();
                q1.pop();
                v1.push_back(cur->val);
                if(cur->left){
                    q1.push(cur->left);
                }
                if(cur->right){
                    q1.push(cur->right);
                }
            }
        }
        
        while(!q2.empty()){
            int sz = q2.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q2.front();
                q2.pop();
                v2.push_back(cur->val);
                if(cur->left){
                    q2.push(cur->left);
                }
                if(cur->right){
                    q2.push(cur->right);
                }
            }
        }
        
        return v1 == v2 ;
        
        
    }
};