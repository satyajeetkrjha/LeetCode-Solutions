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
    
    void dfs(TreeNode *&root,set <int> todeletenodes, vector <TreeNode*> &res){
        if(root == NULL)
            return ;
        
        dfs(root->left,todeletenodes,res);
        dfs(root->right,todeletenodes,res);
        
        if(root!=NULL && todeletenodes.count(root->val) ==1 ){
            
            if(root->left !=NULL){
                res.push_back(root->left);
            }
            if(root->right !=NULL){
                res.push_back(root->right);
            }
            root=NULL;
            delete root;
        }  
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector <TreeNode*> res ;
        set <int> todeletenodes;
        res.clear();
        todeletenodes.clear();
        
        for(int i =0;i<to_delete.size();i++){
           todeletenodes.insert(to_delete[i]);
        }
        
        dfs(root,todeletenodes,res);
        
        if(root!=NULL && todeletenodes.count(root->val)==0){
            res.push_back(root);
        }
        return res ;
        
    }
};