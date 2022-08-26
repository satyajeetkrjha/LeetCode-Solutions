// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    // maximum number of jobs are 50000
    int memo[50001];
    
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& start, int n, int position) {
        // 0 profit if we have already iterated over all the jobs
        if (position == n) {
            return 0;
        }
        // we have already calculated the answer so no need to go into recursion
        if (memo[position] != -1) {
            return memo[position];
        }
        // nextIndex is the index of next non-conflicting job
        // this step is similar to the binary search as in the java solution
        // lower_bound will return the iterator to the first element which is 
        // equal to or greater than the element at `jobs[position][1]`
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1]) - start.begin();
        
        // find the maximum profit of our two options: skipping or scheduling the current job
        int maxProfit = max(findMaxProfit(jobs, start, n, position + 1), 
                        jobs[position][2] + findMaxProfit(jobs, start, n, nextIndex));
        
        // returning maximum profit and also storing it for future reference (memoization)
        return memo[position] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        // marking all values to -1 so that we can differentiate 
        // if we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        
        return findMaxProfit(jobs, startTime, profit.size(), 0);
    }
};