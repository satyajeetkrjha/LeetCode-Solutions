// https://leetcode.com/problems/most-frequent-subtree-sum

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
    int dfs (TreeNode* root , map <int ,int> &m){
        if(!root){
            return 0;
        }
        int leftsum = dfs(root->left,m);
        int rightsum = dfs(root->right,m);
        int totalsum = leftsum +root->val+rightsum;
        m[totalsum]++;
        return totalsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       map <int ,int > m;
       vector <int> ans;
       dfs(root,m);
       int maxval =0;
       map <int ,int >::iterator it ;
        for(it = m.begin();it!=m.end();it++){
            cout<<it->first <<" "<<it->second <<endl;
            maxval = max(maxval ,it->second);
            
        }
        cout<<"maxval is "<<maxval <<endl;
        map <int ,int >::iterator itr ;
        for(itr = m.begin();itr!=m.end();itr++){
           if(itr->second== maxval){
               ans.push_back(itr->first);
           }
        }
        return ans ;
        
    }
};