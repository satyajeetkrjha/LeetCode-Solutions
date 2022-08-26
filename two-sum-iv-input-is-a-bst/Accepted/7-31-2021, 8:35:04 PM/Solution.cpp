// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    set <int> s;
    bool findTarget(TreeNode* root, int k) {
      bool ans = dfs(root,k);
        return ans ;
    }
    bool dfs(TreeNode* root ,int sum){
        if(root == NULL)
            return false;
        if(s.find(sum -root->val) != s.end()){
            return true;
        }
        s.insert(root->val);
        bool left = dfs(root->left,sum);
        bool right = dfs(root->right,sum);
        return left || right ;
        
          
    }
};