// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n  = matrix.size();
        if(n ==0)
            return false ;
        int m = matrix[0].size();
        
        int left = 0 ;
        int right = (m*n)-1;
        
       // cout<<"n is "<<n<<endl;
        //cout<<"m is "<<m <<endl;
        //cout<<"left and right before start are "<<left <<" "<<right <<endl;
        while(left <= right){
            
            int pivot = (left+right)/2;
            int r = pivot /m;
            int c= pivot % m;
            //cout<<"left "<<left <<endl;
            //cout<<"right "<<right <<endl;
            //cout<<"pivot is "<<pivot <<endl;
            //cout<<"r and c before breaking is "<<r << c <<endl;
            if(matrix[r][c] == target){
                return true;
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