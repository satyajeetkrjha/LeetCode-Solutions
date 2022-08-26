// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    int maxval =1;
    void bfs(TreeNode* root){
        int currentleft =1;
        int currentright=1;
        queue <TreeNode*> q;
        q.push(root);
        
        bool leftflag =false;
        bool rightflag =false;
        while(!q.empty()){
            int sz =q.size();
            for(int i=0;i<sz;i++){
                TreeNode * cur = q.front();
                q.pop();
                
                 leftflag =false;
                 rightflag =false;
                cout<<"cur->val is "<<cur->val<<endl;;
                if(cur->left){
                    if(cur->left->val - cur->val == 1){
                        leftflag =true;
                    }
                }
                if(cur->right){
                    if(cur->right->val - cur->val ==1){
                        rightflag =true;
                    }
                }
                if(cur->left){
                    cout<<"cur->left->val is "<<cur->left->val<<endl;
                     q.push(cur->left);
                }
                if(cur->right){
                     cout<<"cur->right->val is "<<cur->right->val<<endl;
                    q.push(cur->right); 
                }
                   
                   
            }
        
                    if(leftflag){
                        currentleft++;
                        maxval =max(maxval,currentleft);
                    }
                   if(rightflag){
                      currentright++;
                      maxval=max(maxval,currentright);
                   }
                   if(!leftflag){
                       currentleft =1;
                   } 
                  if(!rightflag){
                      currentright =1;
                  }
              }
      }

                    
    
    int longestConsecutive(TreeNode* root) {
        if(!root){
            return 0;
        }
        bfs(root);
        return maxval;
        
    }
};