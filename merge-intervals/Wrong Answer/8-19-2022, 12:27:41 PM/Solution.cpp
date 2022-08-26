// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int> > res ;
        
        int n = intervals.size();
        res.push_back(intervals[0]);
        for(int i =1 ;i<n;i++){
              int sz = res.size();
             if(res[sz-1][1]>= intervals[i][0]){
                 res[sz-1][1] = max(res[sz-1][1],intervals[i][1]);
                 res[sz-1][0] = min(res[sz-1][0],intervals[i][0]);
             }
            else
            res.push_back(intervals[i]);
        }
    
        return res ;
    }
};