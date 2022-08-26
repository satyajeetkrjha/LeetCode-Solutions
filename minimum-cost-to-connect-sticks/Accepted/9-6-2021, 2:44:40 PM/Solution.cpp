// https://leetcode.com/problems/minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue <int ,vector<int> ,greater<int> > pq;
        for(int i =0 ;i<sticks.size();i++){
            pq.push(sticks[i]);
        }
        
        // we created a min heap 
        int cost =0 ;
        while(pq.size()>=2){
            int val1= pq.top() ;pq.pop();
            int val2 = pq.top();pq.pop();
            cost+= (val1+val2);
            pq.push(val1+val2);
        }
        return cost ;
        
    }
};