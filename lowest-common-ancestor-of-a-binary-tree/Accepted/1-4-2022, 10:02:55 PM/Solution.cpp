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
        map <TreeNode* ,TreeNode*> m ;
        set <TreeNode*> s ;
        stack <TreeNode*> st ;
        st.push(root);
        m[root] =NULL;
        while(m.find(p) == m.end() || m.find(q) == m.end()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->left){
                st.push(cur->left);
                m[cur->left] = cur;
            }
            if(cur->right){
                st.push(cur->right);
                m[cur->right] = cur;
            }
            
        }
        
        while(p!=NULL){
            s.insert(p);
            p = m[p];
        }
        while(s.count(q) == 0){
            q= m[q];
        }
        
        return q;
    }
};