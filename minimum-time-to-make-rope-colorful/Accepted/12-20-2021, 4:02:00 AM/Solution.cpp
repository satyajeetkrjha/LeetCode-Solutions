// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& cost) {
        
        int res =0;
        
        for(int i =1 ;i<colors.size();i++){
            if(colors[i] == colors[i-1]){
                res += min (cost[i],cost[i-1]);
                cost[i] = max(cost[i],cost[i-1]);
            }
        }
        return res ;
    }
};