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
    void dfs (TreeNode* root ,map <TreeNode*,TreeNode*> &parent){
        if(!root){
            return;
        }
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]= root ;
        }
        dfs(root->left,parent);
        dfs(root->right,parent);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector <int > res; 
        if(!root){
            return res;
        }
        map <TreeNode* ,TreeNode* > parent ; // (key is node and val is parent of that node)
        set <TreeNode*> visited;
        
        // construct the graph first
        dfs(root,parent);
        queue <TreeNode*> q;
        q.push(target);
        int level =0;
        while(!q.empty()){
            int sz = q.size();
            cout<<"sz is "<<sz<<endl;
            for(int i =0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                visited.insert(cur);
                cout<<"level is "<<level <<endl;
                if(level == k && cur){
                    res.push_back(cur->val);
                }
                // current node has a parent node and that node is not visited
                
                if(parent.count(cur)>0 && parent[cur]!=NULL && visited.find(parent[cur]) == visited.end()){
                    q.push(parent[cur]);
                }
                if(cur->left!=NULL &&  visited.find(cur->left) == visited.end()){
                    q.push(cur->left);
                }
                if(cur->right!=NULL && visited.find(cur->right) == visited.end()){
                    q.push(cur->right);
                }
            }
            if( level ==k){
                break;
            }
            level++;
            
        }
        return res;
    }
};