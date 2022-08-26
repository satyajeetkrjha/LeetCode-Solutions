// https://leetcode.com/problems/lonely-pixel-i

class Solution {
    
public:
     int dx[4]={-1,1,0,0};
    int dy[4] ={0,0,-1,1};
    bool dfs(vector<vector<char>>& picture ,int r ,int c){
   
       if(picture [r][c] == 'W'){
           return false;
       }
        for(int i=0;i<4;i++){
            if( r+dx[i] >=0 && r+ dx[i]<=picture.size()-1 && c >=0 && c +dy[i]<=picture[0].size()-1)
            dfs(picture ,r+dx[i],c+dy[i]);
        }  
        return true ;
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
      int rows = picture.size();
      int cols = picture[0].size();
        int count =0;
        bool flag = false ;
      for(int i=0;i<rows;i++){
          for(int j =0;j<cols;j++){
              if(picture[i][j] == 'B'){
                bool flag = dfs(picture ,i,j);
                  if(flag){
                      count++;
                  }
              }
          }
      }  
        return count ;
        
    }
};