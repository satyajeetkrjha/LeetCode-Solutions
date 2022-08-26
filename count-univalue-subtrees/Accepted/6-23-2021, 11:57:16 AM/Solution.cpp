// https://leetcode.com/problems/count-univalue-subtrees

typedef pair<int,int> range;
range combine(const range& a, const range& b) {
  return {min(a.first,b.first), max(a.second,b.second)};
}

class Solution {
 public:
  int ans;
  range dfs(TreeNode* root) {
    if (!root) return {INT_MAX, INT_MIN};
    //range is the datatype equal to pair<int,int>
    //ret is the variable name
    //range ret{a,b} means initialise ret with .first as a and .second as b
    //this is called brace initialisation  
    range ret{root->val, root->val};
    ret = combine(ret, combine(dfs(root->left), dfs(root->right)));
    if (ret.first == ret.second) ans++;

    return ret;
  }
  int countUnivalSubtrees(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
  }
};