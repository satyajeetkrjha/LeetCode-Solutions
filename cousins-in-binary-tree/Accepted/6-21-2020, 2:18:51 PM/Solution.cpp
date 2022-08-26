// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        bool xfound =false;
        bool yfound =false;
        
        q.push(root);
        while(q.size()>0){
            int sz =q.size();
            cout<<"Queue before processing"<<endl;
            cout<<"queue size is "<<sz<<endl;
            for(int i=0;i<sz;i++){
            TreeNode* cur =q.front();
            q.pop();
            if(cur ->left && cur->left->val ==x && cur->right && cur->right->val ==y){    
            
                return false;
            }
            if(cur->left && cur->left->val == y && cur->right && cur->right->val ==x){
                return false;
            }
    
            if(cur->val ==x){
                xfound=true;
            }
            if(cur->val ==y){
                yfound =true;
            }
                cout<<"cur->val is "<<cur->val<<endl;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            cout<<"queue size after pushing is"<<q.size()<<endl;
            }
            cout<<"xfound"<<xfound<<endl;
            cout<<"yfound"<<yfound<<endl;
            if(xfound && yfound )
            return true;
           if(xfound || yfound )
              return false;
             
        }
        return false;
        
    }
};