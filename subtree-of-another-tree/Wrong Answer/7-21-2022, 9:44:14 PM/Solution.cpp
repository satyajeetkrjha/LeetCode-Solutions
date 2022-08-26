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
    
    bool isIdentical(TreeNode* p ,TreeNode* q){
        if(p ==  NULL &&  q==NULL)
            return true ;
        if(p ==NULL ||  q ==  NULL)
            return false ;
      //  cout <<"reached"<<p->val <<" "<< q->val << " "<<endl;
        return p->val == q->val && isIdentical(p->left,q->left) && isIdentical(p->right ,q->right);
    }
    
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root == NULL && subRoot == NULL)
           return true ;
        if(root== NULL || subRoot ==NULL)
            return false ;
       
        return isIdentical(root->left,subRoot ) || isIdentical(root->right,subRoot);
    }
};