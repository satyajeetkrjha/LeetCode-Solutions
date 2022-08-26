// https://leetcode.com/problems/cut-off-trees-for-golf-event

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int> > trees;
    int cutOffTree(vector<vector<int>>& forest) {
       int n = forest.size();
       int m = forest[0].size();
       if(n == 0 || m == 0)
           return 0;
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(forest[i][j] >1)
                trees.push_back({forest[i][j],i,j});
            }
        }
        
        sort(trees.begin(),trees.end()) ;
        
        int ans =0 ;
        int curRow = 0 ;int curCol = 0 ;
        for(int i =0 ;i<trees.size();i++){
            int steps = bfs(forest,curRow,curCol,trees[i][1],trees[i][2]);
            if(steps == -1)
                return -1;
            ans += steps;
            curRow = trees[i][1];
            curCol = trees[i][2];
        }
        return ans ;
    }
    int bfs(vector<vector<int>>& forest ,int sr,int sc,int dr,int dc){
        queue <pair <int ,int> > q ;
        q.push({sr,sc});
        int steps = 0;
        
        int n = forest.size();int m = forest[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[sr][sc] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto [r,c] = q.front() ;
                q.pop();
                if( r == dr && c == dc)
                    return steps ;
                
                for(int i =0 ;i<4;i++){
                    int nr = r+dx[i];
                    int nc = c+dy[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m || forest[nr][nc]==0 || visited[nr][nc] == true)
                        continue;
                    
                        visited[nr][nc] = true;
                        q.push({nr,nc});

                }
            }
            steps++;
        }
        return -1;
    }
};