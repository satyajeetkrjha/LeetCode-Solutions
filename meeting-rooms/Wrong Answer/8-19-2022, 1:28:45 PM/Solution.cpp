// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(),intervals.end());
        int n = intervals.size()-1;
        for(int i =0 ;i<n-1;i++){
            auto it1 = intervals[i];
            auto it2 = intervals[i+1];
            if(it1[1] >it2[0]){
                return false;
            }
        }
        return true ;
    }
};