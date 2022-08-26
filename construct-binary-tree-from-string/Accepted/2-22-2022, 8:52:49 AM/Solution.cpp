// https://leetcode.com/problems/construct-binary-tree-from-string

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
#include <string>
class Solution {
public:
    int start =0;
    TreeNode* str2tree(string s) {
        if(start>=s.size()){
            return NULL;
        }
        
        bool neg = false;
        if(s[start] == '-'){
            neg = true;
            start ++;
        }
        
        int num =0 ;
        
        while(start <s.size() && isdigit(s[start])){
            num = num*10 + (s[start]-'0');
            start ++;
        }
        
        if(neg) num = num *-1;
        
        TreeNode* root = new TreeNode(num);
        
        if(start >= s.size()){
            return root;
        }
        
        if(start < s.size() && s[start] == '('){
            start ++;
            root->left = str2tree(s);
        }
        if(start < s.size() && s[start] == ')'){
            start ++;
            return root ;
        }
        if(start < s.size() && s[start] =='('){
            start ++;
            root->right = str2tree(s);
        }
        if(start < s.size() && s[start]  ==')'){
            start ++;
            return root ;
        }
    
        return root ;
        
        
    }
};