// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans ;
        
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int sum =0;
            for(int i =0 ;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                sum +=cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                
                
            }
            double average =(double) sum/sz;
            ans.push_back(average);
        }
        return ans ;
        
    }
};