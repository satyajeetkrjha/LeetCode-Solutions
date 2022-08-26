// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        
        
        for(int i = 0;i<intervals.size();i++){
            auto interval1 = intervals[i];
            auto interval2 = intervals[i+1];
            if(interval1[1] >= interval2[0])
                return false ;
        }
        return true ;
        
        
        
        
    }
};