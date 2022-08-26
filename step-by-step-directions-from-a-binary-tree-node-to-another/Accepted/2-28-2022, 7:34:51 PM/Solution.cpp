// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    
    TreeNode* lcafinder (TreeNode* root ,int startvalue ,int destvalue){
        if(root == NULL){
            return NULL;
        }
        if(root->val == startvalue || root->val == destvalue){
            return root;
        }
        
        auto left = lcafinder(root->left,startvalue,destvalue);
        auto right = lcafinder(root->right,startvalue,destvalue);
        
        if(left!=NULL && right!=NULL){
            return root ;
        }
        
      return !left ? right: !right ? left:NULL; 
        
    }
    
    bool search(TreeNode* root ,int startvalue ,string &s){
        
        if(root ==NULL)
            return false;
        
        if(root->val == startvalue){
            return true;
        }
        
        auto leftsearch = search(root->left,startvalue,s+='L');
        if(leftsearch){
            return true;
        }
        s.pop_back();
        
        
        auto rightsearch = search(root->right,startvalue,s+='R');
        if(rightsearch){
            return true;
        }
        s.pop_back();
        return false;
        
    }
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode*  lca = lcafinder(root,startValue,destValue);
        string s1 ,s2 ;
        search(lca,startValue,s1);
        search(lca,destValue,s2);
        for(auto &it:s1){
            it='U';
        }
        
        return s1+s2;
        
        
        
        
        
        
    }
};