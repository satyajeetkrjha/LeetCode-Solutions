// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      
        int firstrowzero = false ;
        int firstcolumnzero = false;
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(matrix[i][j] == 0){
                    if( i ==0 ){
                        firstrowzero = true;
                    }
                    if(j == 0 ){
                        firstcolumnzero = true;
                    }
                    matrix[i][0] = matrix[0][j] =0;
                }
            }
        }
        
        for(int i=1;i<R;i++){
            for(int j=1;j<C;j++){
                if(matrix[i][0] == 0 || matrix[0][j] ==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firstrowzero){
            for(int i=0;i<C;i++){
                matrix[0][i] =0;
            }
        }
        if(firstcolumnzero){
            for(int i=0;i<R;i++){
                matrix[i][0] =0;
            }
        }
        
    }
};