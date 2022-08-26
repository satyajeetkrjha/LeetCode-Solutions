// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans =0;
        while(!q.empty()){
            int sz =q.size();
           // cout<<"sz is "<<sz<<endl;
            ans+=sz;
           // cout<<"ans is "<<ans<<endl;
            for(int i=0;i<sz;i++){
                TreeNode* cur =q.front();
                q.pop();
              //  cout<<"cur->val is"<<cur->val<<endl;
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
          //  cout<<"after loop"<<endl;
        }
        return ans;
    }
};