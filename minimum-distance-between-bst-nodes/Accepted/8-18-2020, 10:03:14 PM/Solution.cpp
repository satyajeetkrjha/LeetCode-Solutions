// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int minDiffInBST(TreeNode* root) {
        if(!root){
            return 0;
        }
        vector <int> v;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           
            int sz = q.size();
            for(int i =0;i<sz;i++){
              TreeNode* cur = q.front();
               q.pop();
               v.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
       sort(v.begin(),v.end());
        int diff =INT_MAX;
        for(int i=1;i<v.size();i++){
            diff =min(diff,v[i]-v[i-1]);
        }
        return diff ;
            
    }
};