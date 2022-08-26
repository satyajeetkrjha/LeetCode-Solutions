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
    void dfs(TreeNode* root ,map <TreeNode*,TreeNode*> & parent){
        if(root == NULL)
            return ;
        if(root->left !=NULL){
            parent[root->left] = root ;
        }
        if(root->right!=NULL){
            parent[root->right] = root ;
        }
        dfs(root->left,parent);
        dfs(root->right ,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <TreeNode* ,TreeNode*> parent;
        dfs(root ,parent);
        cout <<"child "<< " "<<"parent "<<endl;
        for( auto node : parent){
            cout<<node.first->val << " "<<node.second->val <<endl;
        }
        set <TreeNode*> visited;
        queue <TreeNode*> q ;
        q.push(target);
        int level =0 ;
        vector <int> res;
        while(!q.empty()){
            int sz = q.size();
            cout<<"level is "<<level <<endl;
            cout<<"size is "<<sz<<endl;
            for(int i =0 ;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                visited.insert(cur);
                cout <<"cur->val is "<<cur->val <<endl;
                if(level == k){
                    res.push_back(cur->val);
                }
                if(cur->left!=NULL && visited.find(cur->left) == visited.end()){
                    cout<<"pushing left with value "<<cur->left->val <<endl;
                    q.push(cur->left);
                }
                if(cur->right!=NULL && visited.find(cur->right) == visited.end()){
                    cout<<"pushing right with value "<<cur->right->val <<endl;
                    q.push(cur->right);
                }
                if(parent.count(cur)>0 && visited.find(parent[cur]) == visited.end()){
                    cout<<"pushing parent with value "<<parent[cur]->val <<endl;
                    q.push(parent[cur]);
                }
                
            }
            if(level == k ) break;
            level ++;
        }
        return res ;
    
         
        
    };
};