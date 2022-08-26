// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    
    
    void dfs(vector<vector<int>>& matrix,int r ,int c,vector<vector<int>>& v,int val){
        if(r<0 || c < 0 || r >= matrix.size() || c>= matrix[0].size()){
            return ;
        }
        
        if(v[r][c] == 1)
            return ;
        
        if(matrix[r][c] < val){
           return ;
        }
        v[r][c] =1 ;
        
        dfs(matrix,r+1,c,v,matrix[r][c]);
        dfs(matrix,r-1,c,v,matrix[r][c]);
        dfs(matrix,r,c+1,v,matrix[r][c]);
        dfs(matrix,r,c-1,v,matrix[r][c]);
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      vector <vector<int>> res ;
        if(heights.size() == 0)
            return res ;
        
        int n = heights.size() ;
        if ( n== 0) return res ;
        int m = heights[0].size();
        
        vector <vector<int>>atlantic(n,vector<int>(m,0));
        vector <vector<int>>pacific(n,vector<int>(m,0));
        
        for(int i =0 ;i< m;i++){
            dfs(heights,0,i,pacific,INT_MIN);
            dfs(heights,n-1,i,atlantic,INT_MIN);
        }
        
        for(int i =0 ;i< n;i++){
            dfs(heights,i,m-1,atlantic,INT_MIN);
            dfs(heights,i,0,pacific,INT_MIN);
        }
        
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j<m;j++){
                if(atlantic[i][j]  && pacific[i][j]){
                    vector <int> vec;
                    vec.clear();
                    vec.push_back(i);
                    vec.push_back(j);
                    res.push_back(vec);
                }
            }
        }
    return res ;    
    }
};