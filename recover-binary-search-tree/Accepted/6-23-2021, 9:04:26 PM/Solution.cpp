// https://leetcode.com/problems/recover-binary-search-tree

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
    void inorder(TreeNode* root ,vector <int> & nums){
        if(!root){
            return;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    pair<int,int> swappednodes(vector <int> nums){
        pair<int,int> values ;
        int x =-1;int y=-1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                y = nums[i+1];
                if( x == -1){
                    x =nums[i];
                }
                else
                    break;
                
            }
        }
        values=make_pair(x,y);
        return values ;
    }
    void recover(TreeNode* root ,int x ,int y ,int steps){
        if(root ==NULL) return ;
        if(root->val == x || root->val ==y){
            if(root->val ==x){
                root->val = y;
                steps --;
                if(steps == 0)
                    return;
            }
            else{
                root->val = x;
                steps --;
                 if(steps == 0)
                    return;
            }
        }
        recover(root->left,x,y,steps);
        recover(root->right,x,y,steps);
    }
    void recoverTree(TreeNode* root) {
       vector <int> nums ;
       inorder(root,nums);
       int x =  -1 ;int y =-1;
        for(int i=0;i<nums.size();i++){
            cout<<"nums[i] "<<nums[i]<<endl;
        }
       pair <int,int> values =swappednodes(nums); 
       x = values.first;y = values.second;
        cout<<"x and y are "<<x<<" "<<y<<endl;
       int steps =2;
       recover(root,x,y,steps); 
        
    }
};