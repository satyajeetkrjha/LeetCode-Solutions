// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool flag1 = false;// first row
        bool flag2= false; // first column
        
        for(int i =0;i<n;i++){
            if(matrix[0][i] == 0)
                flag1 = true;
        }
        
        for(int i =0 ;i<n;i++){
            if(matrix[i][0] == 0)
                flag2 = true;
        }
        
        // marker approach
        for(int i =1 ;i<n;i++){
            for(int j =1 ;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] =matrix[0][j] = 0;
                }
            }
        }
        
        for(int i =1 ;i<n;i++){
            for(int j =1 ;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] =0;
                }
            }
        }
        
        if(flag1){
            for(int i =0 ;i<n;i++){
                matrix[0][i] =0;
            }
        }
        
        if(flag2){
            for(int i =0 ;i<n;i++){
                matrix[i][0] =0;
            }
        }
        
        
        
        
        
    }
};