// https://leetcode.com/problems/minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
         priority_queue <int,vector <int> ,greater<int> > pq;
        
        for(int i=0;i<sticks.size();i++){
            pq.push(sticks[i]);
        }
        int sum =0;
        while(pq.size() >1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            cout<<"first "<<first<<endl;
            cout<<"second "<<second<<endl;
            int cost = first+second ;
            cout<<"cost is "<<cost <<endl;
            sum+=cost;
            pq.push(cost);
        }
        return sum;
        
    }
};