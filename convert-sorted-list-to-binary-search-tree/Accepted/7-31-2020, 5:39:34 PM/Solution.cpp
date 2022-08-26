// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
       vector <int> v;
       ListNode* cur = head;
        while(cur!=NULL){
            v.push_back(cur->val);
            cur = cur->next;
        }
        int n = v.size();
        if( n ==0)
            return NULL;
        int left =0;
        int right =n-1;
        TreeNode* ans =buildBst(v,left,right);
        return ans ;
    }
    TreeNode* buildBst(vector <int> &v ,int left ,int right){
        if(left>right){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root ->left = buildBst(v,left,mid-1);
        root->right =buildBst(v,mid+1,right);
        return root; 
        
    }
};