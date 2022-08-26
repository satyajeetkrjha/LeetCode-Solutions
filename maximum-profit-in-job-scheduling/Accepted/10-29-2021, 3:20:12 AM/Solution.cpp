// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int memo[50001];
    
    int maxprofit( vector <vector<int>>& jobs  ,vector <int> &startTime ,int n ,int position){
        if(position == n){
            return 0;
        }
        if(memo[position] != -1){
            return memo[position];
        }
        
        int nextIndex = lower_bound(startTime.begin(),startTime.end(),jobs[position][1]) - startTime.begin();
        
        int maxProfitVal = max(maxprofit(jobs,startTime,n,position+1),
                            jobs[position][2]+ maxprofit(jobs,startTime,n,nextIndex)
                           );
        
         return memo[position] = maxProfitVal;
        
        
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo,-1 ,sizeof(memo));
        vector <vector<int>> jobs ;
        
        int n = profit.size();
        
        for(int i =0 ;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        
        sort(jobs.begin(),jobs.end()) ;// sorting jobs on the basis of the start time
        
        
        // storing all startTimes after sorting them on the basis of the start time
        for(int i =0 ;i<profit.size();i++){
            startTime[i] = jobs[i][0];
        }
        
         return maxprofit(jobs,startTime ,n,0);
    
        
    }
};