// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    
    
    int maxpathsum ;
    int maxgain(TreeNode* root){
        if(!root)
            return 0 ;
        int leftgain = max(maxgain(root->left),0);
        int rightgain = max(maxgain(root->right),0);
        int pathsum = leftgain + rightgain + root->val;
        maxpathsum = max(maxpathsum ,pathsum);
        return root->val + max(leftgain,rightgain);
    }
    
    
    
    
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return maxpathsum;
    }
};