// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>>ans;
        vector <int> v;
        queue <TreeNode*> q;
        TreeNode * cur =root;
       if(root == NULL)
           return ans;
        q.push(cur);
            while(!q.empty()){
                int sz= q.size();
                for(int i=0;i<sz;i++){
                    cout<<"queue size before popping is "<<q.size()<<endl;
                    TreeNode* temp =q.front();
                    q.pop();
                    cout<<"temp->val is "<<temp->val<<" "<<endl;
                   
                    v.push_back(temp->val);
                    if(temp->left!=NULL)
                        q.push(temp->left);
                    if(temp->right!=NULL)
                        q.push(temp->right);
                    cout<<"queue size after pushing is "<<q.size()<<" "<<endl;
                      
                }
                ans.push_back(v);
                v.clear();
            }
        return ans;
        
    }
};