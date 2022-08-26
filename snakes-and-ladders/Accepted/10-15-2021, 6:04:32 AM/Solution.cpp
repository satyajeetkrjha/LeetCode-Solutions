// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    
    pair <int ,int > coordinates (int x ,int n){
        int r = n -(x-1)/n -1;
        int c = (x-1)% n;
        if( r % 2 == n % 2){
            return {r,n-c-1};
        }
        return {r,c};
        
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
      int n = board.size() ;
      bool visited[n+1][n+1];
      
        
      memset(visited ,false,sizeof(visited)); 
      
      int steps = 0;
      queue <int> q ;
      q.push(1);
      visited[n-1][0] = true ;
      while(!q.empty()){
          int sz = q.size();
          for(int i =0 ;i<sz;i++){
              int x = q.front();
              if(x == (n*n))
                  return steps ;
              q.pop();
              for(int j = 1;j<=6;j++){
                  if(j+ x> n*n)
                      break;
                  pair <int ,int> cur = coordinates(x+j,n);
                  if(visited[cur.first][cur.second])
                      continue ;
                  visited[cur.first][cur.second] = true;
                  if(board[cur.first][cur.second]!=-1){
                      q.push(board[cur.first][cur.second]);
                  }
                  else{
                      q.push(j+x);
                  }
                  
              }
          }
          steps ++;
          
      }
        return -1;
        
        
        
    }
};