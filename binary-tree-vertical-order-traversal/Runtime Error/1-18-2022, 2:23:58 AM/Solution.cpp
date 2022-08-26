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
        queue <pair <TreeNode*, int> > q ;
        vector <vector <int> > res ;
        q.push({root,0});
        map <int ,vector <int> > m;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                pair <TreeNode* ,int> pr = q.front();
                q.pop();
                TreeNode* cur = pr.first ;
                int val = pr.second ;
                m[val].push_back(cur->val);
                if(cur->left){
                    q.push({cur->left,val-1});
                }
                if(cur->right){
                    q.push({cur->right,val+1});
                }
                
            }
        }
        
        
        for(auto it :m){
            cout <<"it.first is "<< it.first << endl;
            vector <int> temp = it.second ;
            for(int j =0 ;j< temp.size();j++){
                cout << temp[j]<< "  ";
            }
            cout << endl;
            res.push_back(it.second);
        }
         return res ;
        
        
        
        
    }
};