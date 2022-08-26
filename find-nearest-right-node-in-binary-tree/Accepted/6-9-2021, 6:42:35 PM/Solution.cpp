// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* target) {
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size(); // size of the level we are at 
            for(int i=0;i<sz;i++){
                TreeNode* cur =q .front();
                q.pop();
                if( cur == target){
                    // if current node is the last node at a level in bfs it means there is no node at it's right so return null 
                    if( i == sz-1){
                        return nullptr;
                    }
                    else 
                        return q.front();
                }
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return nullptr;
    }
};