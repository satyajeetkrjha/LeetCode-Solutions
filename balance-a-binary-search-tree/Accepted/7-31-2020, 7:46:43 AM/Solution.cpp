// https://leetcode.com/problems/balance-a-binary-search-tree

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
    vector <int> v;
     void  inorder( TreeNode* root){
        if(root ==NULL )
            return ;
         inorder(root->left);
         v.push_back(root->val);
         inorder(root->right);
    }
    TreeNode* balance(int left, int right){
       if(left>right){
           return NULL;
       }
       int mid =(right+left)/2;
       TreeNode* root = new TreeNode (v[mid]); // create a new node
        root ->left = balance(left,mid-1);
        root->right = balance(mid+1,right);
        return root ;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root ==NULL)
            return root ;
        // first converting binary search treee into sorted array 
        inorder(root);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        // now converted the sorted array into bst 
        int left = 0;
        int  right= v.size()-1;
        TreeNode* ans = balance(left ,right);
        return ans ;
    }
};