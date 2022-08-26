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
        vector <int> vec;
        stack <TreeNode*> st ;
        TreeNode* cur = root ;
        while(cur!=NULL || !st.empty()){
            while(cur!=NULL){
                st.push(cur);
                cur = cur->left ;
            }
            cur = st.top();
            st.pop();
            vec.push_back(cur->val);
            cur = cur->right;
        }
        for(int i=0 ;i<vec.size()-1;i++){
            if(vec[i]>= vec[i+1])
                return false ;
        }
        return true ;
        
        

    }
};