// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
     sort(intervals.begin(),intervals.end());
     for(int i =0 ;i <intervals.size()-1;i++){
         vector <int> v1 = intervals[i];
         int startTime1 = v1[0];
         int endTime1 = v1[1];
         vector <int> v2 = intervals[i+1];
         int startTime2= v2[0];
         int endtime2=v2[1];
         if(endTime1> startTime2){
             return false;
         }
         
     }
        return true;
    }
};