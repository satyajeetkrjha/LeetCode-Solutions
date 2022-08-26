// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& val) {
        
          int n = val.size();
        vector<vector<int>> DP(n, vector<int>(2));
DP[0][1] = val[0];
for(int i=1; i<n; ++i) {
  DP[i][0] = max(DP[i-1][0], DP[i-1][1]);
  DP[i][1] = DP[i-1][0] + val[i];
}
return max(DP[n-1][0], DP[n-1][1]);
    }
};