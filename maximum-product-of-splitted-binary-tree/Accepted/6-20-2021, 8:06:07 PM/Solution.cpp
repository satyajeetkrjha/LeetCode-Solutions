// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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

typedef long long int ll ;
class Solution {
public:
     // this vetor contains sums for all subtree1 as we traverse the tree
    ll  treesum(TreeNode* root, vector <ll> &sums){
        if(root == NULL){
            return 0;
        }
        ll leftsum = treesum(root->left,sums);
        ll rightsum = treesum (root->right,sums);
        ll totalsum = leftsum+root->val+rightsum;
        sums.push_back(totalsum);
        return totalsum;
        
    }
    int maxProduct(TreeNode* root) {
        vector <ll> sums ;
        ll totalsum = treesum(root,sums);
        ll ans =0;
        for(int i=0;i<sums.size();i++){
            ans = max(ans ,(sums[i])*(totalsum-sums[i]));
        }
        return ans%(1000000007);
        
    }
};