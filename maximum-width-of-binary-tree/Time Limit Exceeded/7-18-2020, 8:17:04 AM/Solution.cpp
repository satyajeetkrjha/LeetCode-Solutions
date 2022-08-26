// https://leetcode.com/problems/maximum-width-of-binary-tree

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
#include <deque>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root ==NULL)
            return 0;
        deque <TreeNode*> dq;
        dq.push_back(root);
        int ans = INT_MIN;
        while(!dq.empty()){
            for (auto it =dq.begin(); it != dq.end(); ++it) 
                cout << ' ' << *it; 
            // remove boundary element at the front of dequeue
            while(!dq.empty() && dq.front() ==NULL){
                cout<<"popped from front"<<endl;
                dq.pop_front();
            }
             // remove boundary element at the end of dequeue
            while(!dq.empty() && dq.back() ==NULL)
            {
                cout<<"popped from rear"<<endl;
                dq.pop_back();
            }
            int sz =dq.size(); // take size after all removals 
            ans = max(ans ,sz);
            cout<<"sz is "<<sz<<endl;
            for(int i=0;i<sz;i++){
                TreeNode* cur =dq.front();
                dq.pop_front();
                if(cur ==NULL){ // null nodes which exists between good nodes
                    dq.push_back(NULL);
                    dq.push_back(NULL); 
                }
                else{ ///
                    dq.push_back(cur->left);
                    dq.push_back(cur->right);
                }
                   
            }
        }
            return ans;        
    }
};