// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector <vector <int> > ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <int> v;
        if(root ==NULL)
            return ans;
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            v.clear();
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(v);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};