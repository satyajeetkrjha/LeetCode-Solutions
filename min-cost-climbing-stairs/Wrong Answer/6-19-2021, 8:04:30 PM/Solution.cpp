// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       int minimumcost[n+1];
      
        for(int i=2;i<n;i++){
            // cout<<"minimumcost[i-1]+cost[i-1]"<<minimumcost[i-1]+cost[i-1]<<endl;
            // cout<<" minimumcost[i-2]+cost[i-2] "<<minimumcost[i-2]+cost[i-2]<<endl;
            minimumcost[i] = min(minimumcost[i-1]+cost[i-1],minimumcost[i-2]+cost[i-2]);
            cout<<minimumcost[i]<<endl;
        }
        // for(int i=0;i<n;i++){
        //     cout<<"minimumcost[ "<<i<<" ]"<< minimumcost[i]<<endl; 
        // }
        return minimumcost[n-1];
    }
};