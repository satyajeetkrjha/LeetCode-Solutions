// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n  = matrix.size();
        int m = matrix[0].size();
        
        int left = 0 ;
        int right = (m*n)-1;
        
        while(left <= right){
            int pivot = (left+right)/2;
            int r = pivot /n;
            int c= pivot % n;
            if(matrix[r][c] == target){
                return target;
            }
            else {
                if(matrix[r][c]<target){
                    left = pivot+1;
                }
                else{
                    right = pivot -1;
                }
            }
            
        }
        return false ;
        
        
        
    }
};