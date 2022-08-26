// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        priority_queue <int ,vector<int> ,greater <int> > pq ;
        
        sort(intervals.begin(),intervals.end());
        for(int i =0; i<intervals.size();i++){
            
            /*
            free those rooms whose end times are smaller than the end time of current so at last all those rooms remaining in the min heap will tell u how many rooms you need
            
            */
            if(!pq.empty() && intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
        
        
        
    }
};