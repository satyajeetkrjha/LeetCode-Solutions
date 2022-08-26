// https://leetcode.com/problems/find-distance-in-a-binary-tree

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
    
    TreeNode* lcafinder(TreeNode* root ,int p ,int q){
        if(root == NULL){
            return NULL;
        }
        if(root->val == p || root->val == q){
            return root ;
        }
        
        auto left = lcafinder(root->left ,p,q);
        auto right = lcafinder(root->right,p,q);
        
        if(left!=NULL && right!=NULL){
            return root ;
        }
        return !left ? right :!right ? left :NULL;
        
    }
    
    bool search(TreeNode*  root ,int target ,string &s){
        if(root == NULL){
            return false;
        }
        if(root ->val == target){
            return true ;
        }
        
        auto leftsearch = search(root->left ,target,s+='L');
        if(leftsearch){
            return true ;
        }
        s.pop_back();
        
        auto rightsearch = search(root->right ,target,s+='R');
        if(rightsearch){
            return true;
        }
        s.pop_back();
        return false ;
        
        
        
    }
    
    
    int findDistance(TreeNode* root, int p, int q) {
       TreeNode* lca  = lcafinder(root ,p,q);
       cout << lca->val << endl;
       string s1,s2;
       search(lca,p,s1);
       search(lca,q,s2);
       return s1.size()+s2.size(); 
        
    }
};