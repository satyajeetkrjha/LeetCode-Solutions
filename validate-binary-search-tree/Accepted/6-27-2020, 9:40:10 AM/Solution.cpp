// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        stack <TreeNode*> s;
        vector <int> res;
        // a simple in order traversal nd then check if a[i]<a[i+1]
        TreeNode* cur =root;
        while(!s.empty() || cur!=NULL){
            while(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }
            cur =s.top();
            s.pop();
            res.push_back(cur->val);
            cur =cur->right;
        }
        bool ans=true;
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};