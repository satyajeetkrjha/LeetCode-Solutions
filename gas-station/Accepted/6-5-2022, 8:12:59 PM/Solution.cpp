// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0;
        int totalgas =0;
        for(int i =0 ;i<gas.size();i++){
            totalcost+= cost[i];
            totalgas+= gas[i];
        }
        
        int cur =0;
        int startingpoint =0;
        for(int i =0 ;i<gas.size();i++){
            cur += gas[i]-cost[i];
            if(cur <0){
                cur =0;
                startingpoint = i+1;
                
            }
        }
        if(totalcost >totalgas){
            return -1;
        }
        return startingpoint;
        
    }
};