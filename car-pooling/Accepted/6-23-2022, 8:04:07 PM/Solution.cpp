// https://leetcode.com/problems/car-pooling

class Solution {
public:
    
    priority_queue <pair <int,int>,vector<pair<int,int> > ,greater <pair <int,int>>> pq ;
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        for(int i =0 ;i<trips.size();i++){
            int people = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            pq.push({start,people});
            pq.push({end,-people});
        }
        
        int onboarded = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            onboarded += cur.second ;
            if(onboarded >capacity)
                return false;
        }
        return true ;
    }
};