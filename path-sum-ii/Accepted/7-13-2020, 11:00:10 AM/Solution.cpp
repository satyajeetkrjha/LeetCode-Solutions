// https://leetcode.com/problems/path-sum-ii

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
    vector <vector<int> > ans;
    vector <int> v;
    bool flag =false;
    void dfs(TreeNode* root,int pathsum,int sum){
        cout<<"pathsum is "<<pathsum<<endl;
        if(!root)
            return ;
        pathsum+=root->val;
         v.push_back(root->val);
         printvector(v);
        
        if(root->left ==NULL && root->right ==NULL && pathsum ==sum){
            ans.push_back(v);
            cout<<"vector cleared"<<endl;

        }
       
       
        if(root->left){
            dfs(root->left,pathsum,sum);
        }
        if(root->right){
            dfs(root->right,pathsum,sum);
        }
        if(v.size()>0)
        v.pop_back();
        
    }
    void printvector(vector <int> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
          int pathsum =0;
              if(root== NULL)
                  return ans ;
          dfs(root,pathsum,sum);
        return ans;
    }
    
};