// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
// logic
// if you can count the number of coin moves across each edge
// and add this value for all edges
// then you get the answer
// now take a given edge

// will there be coin moves in both directions on this edge or only one ?
// You :
// in just one direction ,either top to bottom or bottom to top
// good
// we know how many coins are in the subtree in the beginning
// and how many there will be in the end
// every coin move across the edge changes the number of coins in the subtree by 1
// You sent
// correct
// so number of coins moving across an edge = difference between number of nodes and number of coins in subtree
// You sent
// yes makes sense
class Solution {
public:
    int res;
    pair <int, int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        int n =1; int coin = root->val ;
        auto [leftcount ,leftcoins ] = dfs(root->left);
        
        res += abs(leftcount -leftcoins);
        n+=leftcount;
        coin+=leftcoins;
        
        auto [rightcount ,rightcoins] = dfs(root->right);
        res += abs(rightcount - rightcoins);
        n+=rightcount;
        coin +=rightcoins;
        
        return {n,coin};
        
    }
    int distributeCoins(TreeNode* root) {
       res =0;
        dfs(root);
        return res;
    }
};