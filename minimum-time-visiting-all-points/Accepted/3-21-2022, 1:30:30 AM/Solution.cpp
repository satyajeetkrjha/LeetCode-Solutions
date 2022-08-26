// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
     
        int n = points.size();
        int res =0 ;
        for(int i = 1;i<n;i++){
            res += 
                max(abs(points[i-1][1]-points[i][1]),
                    abs(points[i-1][0]-points[i][0]));
        }
        return res ;
        
    }
};