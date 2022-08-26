// https://leetcode.com/problems/01-matrix

class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector <vector <int> > res ;
        int r = mat.size();
        int c = mat[0].size();
        
        for(int i =0 ;i<r ;i++){
             vector <int> temp ; 
            for(int j =0 ;j< c;j++){
               if(mat[i][j] == 0){
                   temp.push_back(0);
               }
                else{
                    int count =1;
                    queue <pair<int ,int> >q;
                    q.push({i,j});
                    bool flag = false;
                    while(!q.empty() && !flag){
                        int sz = q.size();
                    for(int k = 0 ;k<sz && !flag;k++){
                        auto cur = q.front();
                        q.pop();
                        for(int dir = 0 ;dir <4 && !flag;dir++){
                            int nr = cur.first + dx[dir];
                            int nc = cur.second + dy[dir];
                            if(nr<0 || nr >= r || nc <0 || nc >= c){
                                continue;
                            }
                            else{
                                if(mat[nr][nc] ==0){
                                    temp.push_back(count);
                                    flag = true;
                                    break;
                                    
                                }
                                else{
                                    q.push({nr,nc});
                                }
                            }
                        }
                    }
                        count++;
                    
                }
            }
        }
            res.push_back(temp);
        
        }
        return res ;
    }
};