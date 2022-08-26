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
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        queue <TreeNode*> q;
        int level =1;
        q.push(root);
        while(!q.empty()){
            temp.clear();
            int sz= q.size();
            cout<<"Queue before processing "<<sz<<endl;
            cout<<"level is "<<level<<endl;
            for(int i=0;i<sz;i++){
                TreeNode *cur=q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
            }
            cout<<"temp is "<<" ";
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
            if(level%2 ==0)
                reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            level++;
            
        }
        return ans;
    }
};