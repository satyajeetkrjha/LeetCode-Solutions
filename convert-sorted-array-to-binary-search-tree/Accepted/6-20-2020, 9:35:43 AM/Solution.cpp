// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* helper(int start,int end , vector<int>& nums){
        if(start>end)
            return NULL;
        int mid =(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(start,mid-1,nums);
        root->right = helper(mid+1,end,nums);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start =0;
        int end =nums.size()-1;
        TreeNode* ans =helper(start,end,nums);
        return ans;
    }

};