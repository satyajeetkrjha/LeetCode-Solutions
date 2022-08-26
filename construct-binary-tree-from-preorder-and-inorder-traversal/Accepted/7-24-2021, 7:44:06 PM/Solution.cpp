// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    map <int ,int> m;
    TreeNode* build (vector<int>& preorder, vector<int>& inorder ,int &rootIndex ,int start ,int end){
      if(start > end){
          return NULL ;
      }
      int elem = preorder[rootIndex]; // this gives the root
      int index = m[elem];   // find index of that root in inorder traversal 
      TreeNode* root = new TreeNode(elem) ;// construct root with the elem 
      rootIndex++;
      // now build left subtree and right subtree 
      root->left = build(preorder ,inorder,rootIndex, start,index-1);
      root->right =  build(preorder ,inorder,rootIndex, index+1,end);
        return root ;
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i =0 ;i<inorder.size();i++){
            m[inorder[i]] = i ;
        }
        int rootIndex =0;
        int start =0 ;int end = n-1;
        return build(preorder ,inorder ,rootIndex,start,end);
    
    }
};