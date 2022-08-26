// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int ,map <int ,multiset < int> > >m ;
        queue <pair <TreeNode* ,pair <int,int> >> q;
        q.push({root ,{0,0}});
        while(!q.empty()){
            pair <TreeNode* ,pair <int,int>> cur = q.front();
            TreeNode* temp = cur.first ;
            int x = cur.second.first;
            int y = cur.second.second ;
            q.pop();
            m[x][y].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{x-1,y-1}});
                
            }
            if(temp->right){
                q.push({temp->right,{x+1,y+1}});
            }
            
        }
        
        vector <vector<int>> res ;
        for( auto it:m){
            vector <int> temp;
            for(auto val :it.second){
                temp.insert(temp.end(),val.second.begin(),val.second.end());
            }
            res.push_back(temp);
            
        }
        return res;
    }
};