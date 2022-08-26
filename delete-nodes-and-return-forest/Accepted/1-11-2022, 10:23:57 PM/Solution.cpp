// https://leetcode.com/problems/delete-nodes-and-return-forest

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
    set <int> nodestodelete;
    vector <TreeNode*> res ;
    
    void dfs(TreeNode *&root){
        if(!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        if(root!=NULL && nodestodelete.count(root->val)==1){
           // cout <<"root to be deleted"<<root->val <<endl;
            if(root->left){
                res.push_back(root->left);
            }
            if(root->right){
                res.push_back(root->right);
            }
            root =NULL;
            delete root ;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        nodestodelete.clear();
        res.clear();
        nodestodelete.insert(to_delete.begin(),to_delete.end());
        dfs(root);
        if(root!=NULL && nodestodelete.count(root->val) == 0){
            res.push_back(root);
        }
        return res ;
        
        
        
    }
};