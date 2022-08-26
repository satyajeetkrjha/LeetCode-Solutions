// https://leetcode.com/problems/same-tree

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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        if(p == NULL && q ==NULL)
            return true;
        if(p ==NULL || q ==NULL)
            return false;
        queue <TreeNode*> q1;
        queue <TreeNode*> q2;
        q1.push(p); q2.push(q);
        while(!q1.empty() && !q2.empty()){
            auto cur1 = q1.front() ; q1.pop();
            auto cur2 = q2.front() ; q2.pop();
            
            if(cur1->val != cur2->val)
                return false ;
            
            
            
            if(cur1->left && cur2->left){
                 q1.push(cur1->left);
                 q2.push(cur2->left);
            }
            else if(cur1->left || cur2->left)
                return false;
           
            
           if(cur2->right && cur1->right){
               q1.push(cur1->right);
               q2.push(cur2->right);
           }
            else if(cur1->right || cur2->right){
                return false;
            }
        
            
        }
        return true ;
    }
};