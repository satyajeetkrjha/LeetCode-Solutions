// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    
void dfs(vector<vector<int>>& heights,vector<vector<int>>& temp,int r,int c,int val){
    if( r <0 || r>=heights.size() || c <0 || c>= heights[0].size()){
        return;
    }
    
    if(temp[r][c] ==1)
        return ;
   
 
    if(heights[r][c]<val){
        return;
    }
    temp[r][c] =1 ;
    
    dfs(heights,temp,r+1,c,heights[r][c]);
    dfs(heights,temp,r-1,c,heights[r][c]);
    dfs(heights,temp,r,c+1,heights[r][c]);
    dfs(heights,temp,r,c-1,heights[r][c]);
    
    
}
    

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector <vector <int> > res ;
        int n = heights.size();
        int m = heights[0].size() ;
        if(n == 0)
            return res ;
        
        
        vector <vector <int>> pacific(n,vector <int> (m,0));
        vector <vector <int>> atlantic(n,vector <int> (m,0));
        
        for(int i =0 ;i<m ;i++){
            dfs(heights,pacific ,0 ,i,INT_MIN);
            dfs(heights,atlantic,n-1,i,INT_MIN);
        }
        
        for(int i =0 ;i<n ;i++){
            dfs(heights,pacific,i,0,INT_MIN);
            dfs(heights,atlantic,i,m-1,INT_MIN);
        }
        
        for(int i =0 ;i<n;i++){
            for(int j =0;j<m ;j++){
                if(pacific[i][j] ==1 && atlantic[i][j] ==1){
                    vector <int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
            }
        }
        
        return res ;
       
    } 
};