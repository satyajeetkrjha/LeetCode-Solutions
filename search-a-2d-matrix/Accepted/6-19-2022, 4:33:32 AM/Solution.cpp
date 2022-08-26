// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left =0 ;
        int right = n*m -1 ;
        while(left <= right){
            int mid = (left+right)/2 ;
            int row = mid /m ;
            int column = mid%m ;
            if(matrix[row][column] == target){
                return true;
            }
            else {
                if(matrix[row][column]<target){
                    left++;
                }
                else {
                    right --;
                }
                
            }
        }
        return false ;
    }
};