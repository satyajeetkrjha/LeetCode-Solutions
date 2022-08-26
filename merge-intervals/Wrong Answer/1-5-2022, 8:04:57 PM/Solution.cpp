// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        vector<vector <int> > res ;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            int sz = res.size();
            if(res[sz-1][1] > intervals[i][0]){
                res[sz-1][1] = max(res[sz-1][1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
            
        }
        return res ;
        
        
    }
};