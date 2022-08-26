// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <int> rows(n,0);
        vector <int> columns(m,0);
        
        int ans =0 ;
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j< m;j++){
                if(grid[i][j]){
                    ans ++;
                    rows[i]++;
                    columns[j]++;
                }
            }
        }
        
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j< m;j++){
                if(grid[i][j] == 1 && rows[i] ==1 && columns[j] ==1){
                    ans --;
                }
            }
        }
        
        return ans ;
        
    }
};