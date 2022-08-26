// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
       int minimumcost[cost.size()+1];
        
        for(int i=2;i<cost.size()+1;i++){
            cout<<"minimumcost[i-1]+cost[i-1]"<<minimumcost[i-1]+cost[i-1]<<endl;
            cout<<" minimumcost[i-2]+cost[i-2] "<<minimumcost[i-2]+cost[i-2]<<endl;
            minimumcost[i] = min(minimumcost[i-1]+cost[i-1],minimumcost[i-2]+cost[i-2]);
            cout<<minimumcost[i]<<endl;
        }
        
        return minimumcost[cost.size()];
    }
};