// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r =mat.size();
        if( r== 0)
            return mat;
         int c =mat[0].size();
        //https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
        vector <vector <int>> dist (r,vector<int>(c,INT_MAX - 100000));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] ==0){
                    dist[i][j] =0;
                }
                else{
                    if (i > 0){
                        cout<<"dist[i-1][j]+1 is "<<dist[i-1][j]+1<<endl;
                    dist[i][j] = min(dist[i][j],dist[i-1][j]+1);
                }
                if(j >0 ){
                    dist[i][j] = min(dist[i][j],dist[i][j-1]+1);
                }  
                }
                
            }
        }
        for(int i= r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i < r-1){
                    dist[i][j] = min(dist[i][j],dist[i+1][j]+1);
                }
                if(j <c-1){
                    dist[i][j] =min(dist[i][j],dist[i][j+1]+1);
                }
            }
        }
        return dist;
        
    }
};