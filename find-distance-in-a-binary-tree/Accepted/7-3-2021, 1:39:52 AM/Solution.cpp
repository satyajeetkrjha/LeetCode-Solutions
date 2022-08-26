// https://leetcode.com/problems/find-distance-in-a-binary-tree


class Solution {
public:
    
    TreeNode* lca(TreeNode *root ,int p ,int q){
        if(root ==NULL)
            return NULL;
        if(root-> val == p || root-> val == q){
            return root;
        }
        TreeNode *left = lca(root->left,p,q);
        TreeNode *right = lca(root->right,p,q);
        if(left && right)
            return root;
        return left ? left:right;

    }
    int findDistance(TreeNode* root, int p, int q) {
        // find the lca and do bfs from the lca node and use depth concept to solve
        TreeNode* lcanode = lca(root,p,q);
        int dp= -1; // depth to node p
        int dq= -1; // depth to node q
        int d =0;
        queue <TreeNode*> qu;
        qu.push(lcanode);
        cout<<"lca is "<<lcanode->val<<endl;
        while(!qu.empty() && (dp == -1 || dq == -1)){
            int sz = qu.size();
            cout<<"sz is "<<sz<<endl;
            for(int i =0;i<sz;i++){
                TreeNode * cur = qu.front();
                qu.pop();
                cout<<"cur val is "<<cur->val<<endl;
                if(cur->val == p) dp =d;
                if(cur->val == q) dq =d;
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }
            d++;
            
        }
        return dp+dq;
    }
};