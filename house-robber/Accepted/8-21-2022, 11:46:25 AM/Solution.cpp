// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& val) {
        /*
        define DP(i, bool taken) as maximum sum you can get from first i if status of i is taken (true/false)
then clearly DP(0,0) = 0 and DP(0,1) = val[1]
for i > 1, DP(i, 0) = max(DP(i-1,0), DP(i-1,1)) because if you don't take i there is no constraint on whether you take i-1
and DP(i,1) = DP(i-1,0) + val[i] because you cannot take i-1
        
        
        
        */
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