// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
        int minimumcost[n+1];
        for(int i =0;i<n+1;i++){
            minimumcost[i]=0;
        }
        for(int i=2;i<=n;i++){
             minimumcost[i] = min(minimumcost[i-1]+cost[i-1],minimumcost[i-2]+cost[i-2]);
            cout<<minimumcost[i]<<" with index is "<<i<<endl;
        }
        
        return minimumcost[n];
      
    }
};