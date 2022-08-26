// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
     
        int rows = matrix.size();
        if(rows == 0)
            return 0 ;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        
        int dp [rows][cols];
        memset(dp,0,sizeof(dp));
        
        for(int i =0 ;i< rows;i++){
            for(int j =0 ;j<cols ;j++){
                if(matrix[i][j] =='1'){
                    dp[i][j] =1 ;
                }
            }
        }
    
        
        for(int i =0 ;i<rows ;i++){
            for(int j =0 ;j<cols ;j++){
                cout << dp[i][j]<< " ";
            }
            cout << endl;
        }
        
            
        
        int ans = INT_MIN;
        for(int i =0 ;i<rows ;i++){
            for(int j =0 ;j<cols ;j++){
                if(i >0 && j>0){
                     int val = matrix[i][j] == '1'? 1 :0;
                     dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+val;
                     
                }
                ans = max(ans ,dp[i][j]);
            }
        }
        
        cout <<"after filling dp tables"<< endl;
        
        for(int i =0 ;i<rows ;i++){
            for(int j =0 ;j<cols ;j++){
                cout << dp[i][j]<< " ";
            }
            cout << endl;
        }
        
        
        return ans*ans ;
        
        
        
    }
};