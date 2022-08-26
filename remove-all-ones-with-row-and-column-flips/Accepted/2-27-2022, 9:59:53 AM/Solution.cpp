// https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols =  grid[0].size();
        
        for(int i =1 ;i< rows;i++){
            bool pattern = grid[i][0] == grid[0][0];
            for(int j =0 ;j< grid[i].size();j++){
                if(pattern && grid[0][j]!=grid[i][j]){
                    return false;
                }
                if(!pattern && grid[0][j]==grid[i][j]){
                    return false;
                }
            }
        }
        return true ;
        
    }
};