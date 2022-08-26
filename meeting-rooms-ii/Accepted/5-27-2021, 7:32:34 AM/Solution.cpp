// https://leetcode.com/problems/meeting-rooms-ii

#include <iostream>
#include <algorithm>
int min_rooms =INT_MAX;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       if(intervals.size() == 0){
           return 0;
       }
       sort(intervals.begin(),intervals.end());
       priority_queue <int ,vector<int> ,greater<int> > pq;
       for(int i=0;i<intervals.size();i++){
           vector<int> interval =intervals[i];
            if(!pq.empty() && interval[0]>=pq.top()){
               pq.pop();
                cout<<"Element pooped"<<endl;
           }
           cout<<"pushed "<<interval[1]<<endl;
           pq.push(interval[1]);
       }
        return pq.size();
        
    }
};