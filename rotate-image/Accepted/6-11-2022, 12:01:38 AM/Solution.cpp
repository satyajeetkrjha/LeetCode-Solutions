// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size() ;
        int m = matrix[0].size();
        
        
        for(int i =0 ;i< n;i++){
            for(int j = i+1 ;j<m;j++){
               // cout << i << " "<< j<<endl;
                //cout << j << " "<< i << endl;
                swap(matrix[i][j] ,matrix[j][i]);
            }
        }
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m/2 ;j++){
                swap(matrix[i][j],matrix[i][m-j-1]);
            }
        }
        
        
        
    }
};