// https://leetcode.com/problems/binary-tree-vertical-order-traversal

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
       
        // For approach https://www.youtube.com/watch?v=PQKkr036wRc
        map <int ,vector <int>> m; // for every horizontal distance, we will store all corresponding node's values for that distance 
        queue <pair<TreeNode*,int>>q;
        vector <vector <int> > ans;
        if(!root){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            int sz =q.size();
            for(int i=0;i<sz;i++){
               TreeNode* currNode =q.front().first;
               int currdist=q.front().second;
                q.pop();
                m[currdist].push_back(currNode->val); // map a key to vector so push
                if(currNode->left){
                    q.push({currNode->left,currdist-1});
                }
                if(currNode->right){
                    q.push({currNode->right,currdist+1});
                }
                
                
            }
        }
        for (auto i :m){
           
            ans.push_back(i.second);
        }
        return ans;
        
    }
};