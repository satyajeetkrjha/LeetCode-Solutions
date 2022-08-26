// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n =A.size();
        int m =B.size();
        if(n ==0 || m ==0)
            return 0;
        int dp[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i] == B[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};