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
        queue <pair <TreeNode*,int> > q ;
        q.push({root,0});
        map <int ,vector <int> > m;
        vector <vector <int> > res ;
        if(!root)
            return res ;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                TreeNode* temp = cur.first ;
                int val = cur.second ;
                m[val].push_back(temp->val);
                if(temp->left){
                    q.push({temp->left ,val-1});
                }
                if(temp->right){
                    q.push({temp->right ,val+1});
                }
            }
        }
        for(auto &it:m){
            //cout << it.first << " ";
            res.push_back(it.second);
        }
        cout << endl;
        return res ;
    }
};