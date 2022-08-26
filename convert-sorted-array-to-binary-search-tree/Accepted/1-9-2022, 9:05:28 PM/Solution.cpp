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
    
    TreeNode* convert(vector <int> nums ,int low ,int high){
        if(low > high){
            return NULL;
        }
        int mid =(low+high)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res ->left = convert(nums ,low ,mid-1);
        res ->right = convert(nums,mid+1,high);
        return res ;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums ,0 ,n-1);
        
    }
};