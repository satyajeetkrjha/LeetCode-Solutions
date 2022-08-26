// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int memo[205][205];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
      
        for(int i =0;i<205;i++){
            for(int j =0;j<205;j++){
                memo[i][j] = -1;
            }
        }
        int ans = 0;
        for(int i =0 ;i<n;i++){
            for(int j =0;j<m;j++){
                int val = dfs(matrix,n,m,i,j);
                ans = max(ans ,val);
            }
        }
        return ans ;
    
    }
    int dfs(vector<vector<int>>& matrix ,int n,int m, int r ,int c ){
        if(memo[r][c] >0) return memo[r][c];
        int dx[4] ={0 ,-1,1,0};
        int dy[4] ={1,0,0,-1};
        int ans =0;
        
        for(int i  =0;i<4;i++){
            int nr = r +dx[i]; int nc = c+ dy[i];
            if( nr >=0 && nc>=0 && nr < r && nc <m && matrix[nr][nc]> matrix[r][c]){
                ans = max(ans,dfs(matrix ,n,m,nr,nc));
            }
        }
        cout<<"r and c are "<<r <<" "<< c<<endl;
        memo[r][c] = ++ans;
        cout<<"memo[r][c] is "<<memo[r][c]<<endl;
        return ++ans ;
     }
    
    
};