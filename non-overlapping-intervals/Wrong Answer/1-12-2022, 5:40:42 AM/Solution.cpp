// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        
        sort(intervals.begin(),intervals.end());
        int ans =0;
        vector<int> prev = intervals[0];
        for(int i =1 ;i<intervals.size();i++){
            if(prev[1]>intervals[i][0]){
                ans ++;
            }
            else{
                prev = intervals[i];
            }
        }
        return ans ;
        
    }
};