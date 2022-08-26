// https://leetcode.com/problems/closest-binary-search-tree-value

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
    void minDiffFun(TreeNode *root,double target,double &minDiff, int &closestnode){
        if(root == NULL){
            return ;
        }
        double diff = abs(root->val -target);
        
        if(minDiff > diff){
            minDiff =diff;
            cout<<"minDiff in if  "<<minDiff<<endl;
            cout <<"val is "<<root->val<<endl;
            closestnode =root->val;
        }
        if (target <root->val){
            minDiffFun(root->left,target,minDiff,closestnode);
        }
        else {
             minDiffFun(root->right,target,minDiff,closestnode);
        }
    }
    int closestValue(TreeNode* root, double target) {
        double minDiff = abs(root->val - target);
        cout<<"minDiff first "<<minDiff<<endl;
        int closestnode =root->val;
        minDiffFun(root,target,minDiff,closestnode);
        return closestnode;
    }
};