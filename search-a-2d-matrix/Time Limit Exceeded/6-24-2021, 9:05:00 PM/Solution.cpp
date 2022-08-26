// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m  = matrix.size(); // m rows
      int n = matrix[0].size();// n columns
       if( m == 0)
           return false ;
        int left = 0;int right = (m*n)-1;
        while(left <= right){
            int pivotindex =(left+right)/2;
            int pivotelement = matrix[pivotindex/n][pivotindex%n];
            if(pivotelement == target){
                return true;
            }
            else {
                if(pivotelement <target){
                    left = pivotindex+1;
                }
                else {
                    right =pivotindex+1;
                }
            }
        }
        return false ;
        
        
    }
};