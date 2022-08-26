// https://leetcode.com/problems/maximal-square

#include <algorithm>
#include <math.h>
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows =matrix.size();
        if(rows ==0)
            return 0;
        int columns =matrix[0].size();
        if(columns ==0)
            return 0;
        cout<<"rows"<<rows<<endl;
        cout<<"colums"<<columns<<endl;
        int dp[rows+1][columns+1];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]== '1')
                    dp[i][j] =1;
                if(i>0 &&  j>0)
                dp[i][j]+=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                 ans =max(ans,dp[i][j]);
               cout<<"i "<<i<<" j "<<j<<endl;
               cout<<dp[i][j]<<endl;
            }
           
        }
        
        return ans*ans;
        
    }
};