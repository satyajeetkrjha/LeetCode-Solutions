// https://leetcode.com/problems/equal-tree-partition

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
    int treesum(TreeNode* root ,vector <int> &sums){
        if(root ==NULL){
            return 0;
        }
        int leftsum = treesum(root->left,sums);
        int rightsum = treesum(root->right,sums);
        int totalsum = leftsum+ root->val +rightsum;
        sums.push_back(totalsum);
        return totalsum;
    }
    bool checkEqualTree(TreeNode* root) {
        vector <int> sums ;
        int totalsum = treesum(root,sums);
        for(int i =0;i<sums.size();i++){
            int subtree1sum = sums[i];
            if(subtree1sum == (totalsum -subtree1sum)){
                return true;
            }
        }
        return false ;
        
    }
};