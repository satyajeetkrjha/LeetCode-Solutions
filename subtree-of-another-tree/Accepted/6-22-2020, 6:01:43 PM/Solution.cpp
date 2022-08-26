// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isidentical(TreeNode* s, TreeNode* t){
        if( s == NULL && t==NULL){
            return true;
        }
        if(s ==NULL || t==NULL)
            return false;
        
        return (s->val == t->val  &&  isidentical(s->left,t->left)  && isidentical(s->right,t->right));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t ==NULL){ // we want to check if t is a subtree if s and t is empty
            return true;
        }
        if(s==NULL){ // we are checking in s and s tree is null
            return false;
        }
        if(isidentical(s,t))
            return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
        
        
    }
};