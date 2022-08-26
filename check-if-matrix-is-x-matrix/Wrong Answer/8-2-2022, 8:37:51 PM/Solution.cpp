// https://leetcode.com/problems/check-if-matrix-is-x-matrix

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
               if(i == j && grid[i][j]==0)
                   return false;
                else if((i+j) == (n-1) && grid[i][j]==0){
                   return false;
                }
                else if(grid[i][j] != 0)
                    return false;
            }
        }
        return true ;
    }
};