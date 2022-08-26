// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map <TreeNode*,TreeNode*> parent ; 
    void dfs(TreeNode* root){
        if(!root) return ;
        if(root->left){
            parent[root->left] = root ;
        }
        if(root->right){
            parent[root->right] = root ;
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        dfs(root);
        set <TreeNode*> visited ;
        int level =0 ;
        queue <TreeNode*> q ;
        q.push(target);
        vector <int> res;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                visited.insert(cur);
                if(level == k){
                    res.push_back(cur->val);
                }
                
                if(cur->left && visited.find(cur->left) == visited.end()){
                    q.push(cur->left);
                }
                if(cur->right && visited.find(cur->right) == visited.end())                  {
                    q.push(cur->right);
                }
                if(parent.count(cur)>0 && visited.find(parent[cur])==visited.end()){
                q.push(parent[cur]);
                }
            }
            if(level == k)
                   break;
               level++;
        }
               
        return res;
    }
};