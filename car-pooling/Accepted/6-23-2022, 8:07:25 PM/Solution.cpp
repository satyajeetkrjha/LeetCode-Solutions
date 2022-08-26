// https://leetcode.com/problems/car-pooling

class Solution {
public:
    
    priority_queue<pair <int ,int> ,vector <pair <int ,int>> ,greater<pair <int ,int>>> pq ;
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(int i =0 ;i< trips.size();i++){
            int people = trips[i][0];int start = trips[i][1];
            int end = trips[i][2];
            pq.push({start,+people});
            pq.push({end,-people});
        }
        
        int onboarding =0 ;
        while(!pq.empty()){
            onboarding+= pq.top().second ;
            pq.pop();
            if(onboarding> capacity){
                return false;
            }
        }
        return true ;
    }
};