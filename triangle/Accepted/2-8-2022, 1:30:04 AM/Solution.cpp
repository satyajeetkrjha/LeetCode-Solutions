// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        
        for(int i = 1 ;i<rows ;i++){
            for(int j = 0 ;j<=i ;j++){
                int smallestabove = INT_MAX ;
                if(j >0){
                    smallestabove = triangle[i-1][j-1];
                }
                if(j <i){
                    smallestabove = min(smallestabove,triangle[i-1][j]);
                }
                int path = smallestabove + triangle[i][j];
                triangle[i][j] = path;
            }
        }
        
        int ans = INT_MAX;
        for(int i =0 ;i<triangle[rows-1].size();i++){
             ans = min(ans,triangle[rows-1][i]);
        }
        return ans ;
        
        
    }
};