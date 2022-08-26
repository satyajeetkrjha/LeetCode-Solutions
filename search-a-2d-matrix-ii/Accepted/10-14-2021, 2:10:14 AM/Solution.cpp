// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size()-1;
        int c =0;
        
        while( r>=0 && c< matrix[0].size()){
            if(matrix[r][c] >target){
                r --;
            }
            else if(matrix[r][c]<target){
                c++;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};