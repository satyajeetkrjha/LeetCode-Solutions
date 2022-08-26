// https://leetcode.com/problems/maximum-width-of-binary-tree

// this code has been taken from a comment section

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;  
        queue<pair<TreeNode*,int>>q;   // queue containg all pairs in a level
        q.push({root,1});        // push the root node with position 1
        int ans = 1;             //min width will be 1
        while(!q.empty()){
            int sz = q.size();      // get number of nodes in current level
            int minval = INT_MAX,maxval = 0;
            while(sz--){     // for all nodes in this level
                auto node = q.front();q.pop();     // get the pair
                int x = node.second*2;      // to calculate position	
				if(node.first->left){    
                    q.push({node.first->left,x});
                    minval = min(minval,x);
                    maxval = max(maxval,x);
                }
                if(node.first->right){
                    q.push({node.first->right, x - 1 });
                    minval = min(minval,x-1);
                    maxval = max(maxval,x-1);
                }
            }
 // in case there were no children added set minval to 0  as maxval is already 0
            minval = (minval == INT_MAX) ? 0 : minval; 
            ans = max((maxval - minval+1),ans);
        }
        return ans;
    }
};