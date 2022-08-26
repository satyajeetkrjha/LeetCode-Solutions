// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0 ;
        int cur_tank =0 ;
        int startingstation =0 ;
        for(int i =0 ;i<n;i++){
            
            total_tank += gas[i]-cost[i];
            cur_tank+= gas[i]- cost[i];
            if(cur_tank <0){
                cur_tank =0;
                startingstation = i+1;
            }
            
        }
        if(total_tank <0)
            return -1;
        return startingstation;
        
    }
};