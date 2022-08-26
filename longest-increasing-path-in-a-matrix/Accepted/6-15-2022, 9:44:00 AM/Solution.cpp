// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    
    int dx [4] ={1,-1,0,0};
    int dy [4] ={0,0,-1,1};
    int cache[205][205];
    
    
    int dfs(vector<vector<int>>& matrix,int r ,int c){
        if(cache[r][c]>0)
            return cache[r][c];
        for(int i =0 ;i< 4 ;i++){
            int nr = r + dx[i];
            int nc = c+ dy[i];
            if(nr>=0 && nc>=0 && nr <matrix.size() && nc <matrix[0].size()
              && matrix[nr][nc]>matrix[r][c]){
                cache[r][c] = max(cache[r][c],dfs(matrix,nr,nc));
            }
        }
        
       return  ++cache[r][c];
        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size();
        
        memset(cache ,0,sizeof(cache));
        
        int ans =0;
        
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j<m;j++){
                ans = max(ans,dfs(matrix,i,j));
            }
        }
        
       return ans ;
        
        
    }
};