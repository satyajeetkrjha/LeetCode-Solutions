// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int sum =0;
        int diff =0;
        int start =0;
        for(int i=0;i<gas.size();i++){
            sum +=gas[i]-cost[i];
            if(sum<0){
                start =i+1;
                diff+=sum;
                sum=0;
            }
        }
        return sum+diff>=0 ? start:-1;
        
    }
};