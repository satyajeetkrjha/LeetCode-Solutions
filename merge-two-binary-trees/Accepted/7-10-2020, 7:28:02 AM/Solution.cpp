// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)
            return t2;
        if(!t2)
            return t1;
       queue <TreeNode*> q1;
       queue <TreeNode*> q2; 
       q1.push(t1);
       q2.push(t2);
       while(!q2.empty()){
           TreeNode* cur1 =q1.front();
           q1.pop();
           TreeNode* cur2 =q2.front();
           q2.pop();
           cur1->val+=cur2->val;
           if(cur2->left){
               if(cur1->left){
                   q1.push(cur1->left);
                   q2.push(cur2->left);
               }
               else
               cur1->left =cur2->left;
           }
           if(cur2->right){
               if(cur1->right){
                  q1.push(cur1->right);
                  q2.push(cur2->right); 
               }
               else
               cur1->right =cur2->right;
           }
           
       }
        return t1;
    }
};