// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        int maxsum =-INT_MAX;
        
        queue <TreeNode*> q;
        q.push(root);
        
        int sum ;
        int val =1;
         int level =-1;
        while(!q.empty()){
            int sz =q.size();
            int sum =0;
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            cout<<"sum is "<<sum<<endl;
            cout<<"maxsum is "<<maxsum<<endl;
            if(sum > maxsum){
                maxsum =sum;
                level =val;
            }
            val++;
        }
        return level ;
        
    }
};