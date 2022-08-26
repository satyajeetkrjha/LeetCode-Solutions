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
    map <int ,int> m ;
    
    vector <int> preorder,inorder ;
    TreeNode* buildTree(int &rootIndex,int start,int end){
        if(start > end) return NULL;
        int elem = preorder[rootIndex];
        int index = m[elem];
        TreeNode* root = new TreeNode(elem);
        //cout <<"Before :"<< rootIndex << endl;
        rootIndex++;
        //cout <<"After :" << rootIndex << endl;
        root->left = buildTree(rootIndex,start,index-1);
        root->right = buildTree(rootIndex,index+1,end);
        return root;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder1, vector<int>& inorder1) {
        preorder = preorder1;
        inorder = inorder1 ;
        
        for(int i =  0 ;i<inorder.size();i++){
          int x = inorder[i];
          m[x] = i ;
        }
        
        int rootIndex =0;
        return buildTree(rootIndex,0,inorder.size()-1);
        
        
    }
};