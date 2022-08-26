// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
         // construct a min heap
        priority_queue <int ,vector <int> ,greater<int> > pq;
        sort(intervals.begin(),intervals.end()); // this sorts on basis of start time
        for(int i=0 ;i<intervals.size();i++){
            vector <int> v= intervals[i];
            int startTime = v[0];
            int endTime = v[1];
          //  cout<<"satrtTime is "<<startTime <<endl;
           // cout<<"endTime is "<<endTime <<endl;
            if(!pq.empty() && startTime > pq.top()){
                // we don't need an extra room 
                pq.pop();
            }
            pq.push(endTime);
        }
        return pq.size();
         
        
    }
};