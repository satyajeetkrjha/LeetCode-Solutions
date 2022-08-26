// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> largestValues(TreeNode* root) {
        
        vector <int> v;
        if(!root){
            return v;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int maxNum =-INT_MAX;
            for(int i=0;i<sz;i++){
                TreeNode * cur  = q.front();
                q.pop();
                if(cur->val > maxNum){
                    maxNum =cur->val;
                }
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                
            }
            v.push_back(maxNum);
        }
        return v;
    }
};