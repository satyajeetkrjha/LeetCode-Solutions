// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0 ;
        int totalcost = 0 ;
        for(int i =0 ;i<n;i++){
            totalgas += gas[i];
            totalcost+= cost[i];
        }
        if(totalcost >totalgas)
            return -1;
        
        
        int cur =0 ;
        int startingindex =0;
        
        for(int i =0 ;i<n;i++){
            cur += gas[i] - cost[i];
            if(cur <0){
                cur =0;
                startingindex = i+1 ;
            }
        }
        return startingindex;
        
        
    }
};