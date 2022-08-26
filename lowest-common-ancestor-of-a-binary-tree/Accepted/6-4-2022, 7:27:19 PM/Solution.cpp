// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        map <TreeNode*,TreeNode*> parent;
        stack <TreeNode*> st ;
        set <TreeNode*> s ;
        
        st.push(root);
        parent[root] =NULL;
        
        /* we start at root Node and make a parent mapping till our mapping includes both the nodes p and q
        */
        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->left){
                parent[cur->left] = cur;
                st.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur ;
                st.push(cur->right);
            }
        }
        
       while(p!=parent[p]){
           s.insert(p);
           p = parent[p];
       }
        
        while(s.count(q) ==0){
             q= parent[q];
        }
        return q;
        
        
        
        
        
        
    }
};