// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr == NULL){
                foundNull = true ;
            }
            else{
                // we already came across a null node before and we still have nodes in queue 
                if(foundNull){
                    return false;
                }
            
                q.push(curr->left);
                q.push(curr->right);
            }
            
        }
        return true ;
        
    }
};