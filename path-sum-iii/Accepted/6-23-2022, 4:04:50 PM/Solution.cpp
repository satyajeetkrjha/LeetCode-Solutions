// https://leetcode.com/problems/path-sum-iii

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
    int target ;
    int count ;
    map <ll ,ll> m;
    void preorder(TreeNode* root ,ll cursum){
        if(!root){
            return;
        }
        cursum += root->val;
        if(cursum == target){
            count ++;
        }
        count += m[cursum-target];
        m[cursum]++;
        preorder(root->left,cursum);
        preorder(root->right,cursum);
        m[cursum]--;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
      target = targetSum ;
      preorder(root,0);
      return count ;  
        
    }
};