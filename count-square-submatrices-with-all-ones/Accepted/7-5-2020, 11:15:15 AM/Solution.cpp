// https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n =matrix.size();
        if(n ==0)
            return 0;
        int m =matrix[0].size();
        int result =0;
        int cell_value;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0)
                        result++;
                        else {
                            cell_value=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+matrix[i][j];
                            result+=cell_value;
                            matrix[i][j]=cell_value;
                        }
                }
        }
    }
        return result ;
    }
};