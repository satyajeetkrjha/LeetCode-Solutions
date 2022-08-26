// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // rows
        int m = matrix[0].size() ; // columns 
        
        int left =0 ;
        int right = m*n-1;
        while(left <right){
            int mid = (left+right)/2 ;
            int row = mid/m;
            int col = mid % m;
            if(matrix[row][col] == target){
                return true;
            }
            else {
                if(matrix[row][col] <target){
                    left ++;
                }
                else {
                    right --;
                }
            }
        }
        return false ;
        
        
    }
};