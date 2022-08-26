// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    
    priority_queue <int,vector<int> ,greater <int> >pq ;
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int sz = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        for(int i =0 ;i<sz;i++){
            
            if(!pq.empty() && intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
        
    }
};