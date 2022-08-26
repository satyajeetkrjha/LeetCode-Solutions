// https://leetcode.com/problems/recover-binary-search-tree

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
    
    void recoverTree(TreeNode* root) {
       
        stack <TreeNode*> s;
        TreeNode* cur = root ;
        
        TreeNode* x =NULL;
        TreeNode* y =NULL;
        
       
        
        TreeNode  *pre= new TreeNode(INT_MIN);
        while(cur!=NULL || !s.empty()){
            if(cur!=NULL){
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur =s.top();
                s.pop();
                if(pre->val > cur->val){
                    if(x == NULL){
                        x =pre;
                    }
                    if(x!=NULL){
                        y = cur;
                    }
                }
                    pre = cur;
                    cur = cur->right;
                } 
        }
        
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        
        
        
        
    }
};