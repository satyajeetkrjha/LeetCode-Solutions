// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        
        int dx [4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
       
        queue <pair <int,int> > q;
        int count =0 ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == '1'){
                    count ++;
                    grid[i][j] = '2';
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair <int ,int> vertices = q.front();
                        q.pop();
                        for(int dir =0 ;dir<4;dir++){
                        int ndx = vertices.first + dx[dir];
                        int ndy = vertices.second + dy[dir];
                        if(ndx>=0 && ndy >=0 && ndx <n && ndy <m && grid[ndx][ndy] == '1'){
                            q.push(make_pair(ndx,ndy));
                            grid[ndx][ndy]='2';
                        }
                    }
                }
                      
                }
            }
        }
        return count ;
        
    }
};