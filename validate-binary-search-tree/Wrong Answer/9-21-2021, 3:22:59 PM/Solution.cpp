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
       // do a simple inorder traversal and check if the array is sorted or not 
        if(!root) return true;
        vector <int> v ;
        stack <TreeNode*> st;
        TreeNode* cur = root ;
        while(!st.empty() || cur!=NULL){
            // keep going left and push all of them in stack
            while(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            cout <<"stack size is "<<st.size()<<endl;
             cur = st.top();
             st.pop();
            cout<<"cur->val is "<<cur->val <<endl;
            v.push_back(cur->val);
             cur = cur->right;
        }
        cout <<"size of vector is "<<v.size()<<endl;
        for(int i =0 ;i<v.size()-1;i++){
            if(v[i]>v[i+1])
                return false;
        }
        
        return true;
        
    }
};