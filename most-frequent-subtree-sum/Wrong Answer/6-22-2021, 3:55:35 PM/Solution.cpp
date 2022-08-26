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
    int dfs (TreeNode* root , map <int ,vector <int>> &m){
        if(!root){
            return 0;
        }
        int leftsum = dfs(root->left,m);
        int rightsum = dfs(root->right,m);
        int totalsum = leftsum +root->val+rightsum;
        m[totalsum].push_back(totalsum);
        return totalsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       map <int ,vector <int> > m;
       vector <int> ans;
       dfs(root,m);
       int maxval =0;
       map <int ,vector <int> >::iterator it ;
        for(it = m.begin();it!=m.end();it++){
            vector <int> v = it->second ;
            int sz = v.size();
            maxval =max(maxval,sz);
            
        }
        cout<<"maxval is "<<maxval <<endl;
        map <int ,vector <int> >::iterator itr ;
        for(itr = m.begin();itr!=m.end();itr++){
            vector <int> v = itr->second ;
            int sz = v.size();
            if(sz == maxval){
               for(int j =0;j<v.size();j++){
                   ans.push_back(v[j]);
               }  
            } 
        }
        return ans ;
        
    }
};