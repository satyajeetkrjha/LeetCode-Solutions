// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix


class Solution {
public:
 
    map <vector <vector <int> > ,int> dist ;
    map <vector <vector <int> > ,bool> visited ;
    
    int dx[4] ={1,-1,0,0};
    int dy[4]= { 0,0,-1,1};
    
  vector<vector<int>> modify (vector <vector <int> > mat,int r ,int c){
        mat[r][c] = 1-mat[r][c];
        for(int i =0 ;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr>=0 && nc>=0 && nr < mat.size() && nc <mat[0].size()){
                mat[nr][nc] = 1-mat[nr][nc];
            }
        }
      return mat;
    }
    
   
    
    int minFlips(vector<vector<int>>& mat) {
        
        int n= mat.size();
        int m = mat[0].size();
           
        queue <vector<vector <int> > > q ;
        q.push(mat);
        dist[mat] =0 ;
        visited[mat] = true ;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i =0 ;i< mat.size();i++){
                for(int j =0 ;j< mat[0].size();j++){
                    auto newstate = modify(mat ,i,j);
                    if((visited[newstate] == false) ||(dist[newstate] >dist[cur]+1)){
                        dist[newstate] = dist[cur]+1;
                        visited[newstate] = true;
                        q.push(newstate);
                    }
                }
            }
        }
      
        vector < vector <int> > finalstate(n,vector <int> (m,0));
        if(dist.find(finalstate) == dist.end()){
            return -1;
        }
        return dist[finalstate];
        
    }
};