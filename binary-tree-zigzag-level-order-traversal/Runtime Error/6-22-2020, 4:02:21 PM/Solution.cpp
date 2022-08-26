// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > ans;
        vector <int> temp;
        queue <TreeNode*> q;
        q.push(root);
        int level =1;
        while(!q.empty()){
            int sz= q.size();
            temp.clear();
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
            }
           
            if(level%2 ==0)
               reverse(temp.begin(),temp.end());
             ans.push_back(temp);
            level++;

            
        }
        return ans;
    }
};