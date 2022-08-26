// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size();// number of rows
      int m =grid[0].size();
      const int ROTTEN=2;
      const int FRESH_ORANGE=1;
        int rottenOranges=0;
        int freshOranges=0;
        queue<pair<int,int> > q;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==ROTTEN){
                  pair<int,int> coordinate =make_pair(i,j);
                  q.push(coordinate);
                  rottenOranges++;
              }
              else if(grid[i][j]==FRESH_ORANGE){
                  freshOranges++;
                  
              }
          }
      }
        if(freshOranges==0){
            return 0;
        }
        if(rottenOranges ==0){
            return -1;
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int time=0;
        while(q.size()> 0 && freshOranges>0){
            int numRotten =q.size();
            for(int i=0;i<numRotten;i++){
               pair<int,int> curr=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                   int x = dx[i]+curr.first;
                int y =dy[i]+curr.second;
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==FRESH_ORANGE){
                    grid[x][y]=2;
                    freshOranges--;
                    pair<int,int > coordinate =make_pair(x,y);
                    q.push(coordinate);
                    
                }
        } 
                }
               
            time++;
        }
        if(freshOranges ==0){
            return time;
        }
        else
            return -1;
    }
};