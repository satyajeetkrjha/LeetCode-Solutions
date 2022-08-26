// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix

class Solution {
public:
    map < vector<vector<int>>,bool> visited;
    map < vector <vector<int>> ,int> dist;
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    vector<vector<int> > flip(vector<vector<int> >mat,int r ,int c){
        mat[r][c] = 1 -mat[r][c];
        for(int i =0 ;i< 4 ;i++){
            int nr  = r+ dx[i];
            int nc = c+ dy[i];
            if(nr>=0 && nc >=0 && nr < mat.size() && nc < mat[0].size()){
                mat[nr][nc] = 1-mat[nr][nc];
            }
        }
        return mat;
        
    }
    
    
    
    
    int minFlips(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<vector<vector<int>>> q;
        q.push(mat);
        visited[mat] = true;
        dist[mat] =0;
        
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            for(int i =0 ;i< vec.size();i++){
                for(int j =0 ;j< vec[0].size() ;j++){
                    auto nextstate = flip(vec,i ,j);
                    if((visited[nextstate] == false) 
                       || (dist[nextstate] > dist[vec]+1)){
                        dist[nextstate] = dist[vec]+1;
                         visited[nextstate] = true;
                        q.push(nextstate);
                        
                    }
                }
            }   
        }
        
        vector <vector <int> > finalstate ;
        vector <int> temp;
        for(int i =0 ;i<cols;i++){
            temp.push_back(0);
        }
        for(int i =0 ;i< rows;i++){
            finalstate.push_back(temp);
        }
        
        
        
        if(dist.find(finalstate) == dist.end()){
            return -1;
        }
        return dist[finalstate];
    
        
    }
};