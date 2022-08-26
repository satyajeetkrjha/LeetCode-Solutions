// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int> > ans;
        int sz = intervals.size();
        if(sz ==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<sz;i++){
            int ans_size=ans.size();
            if(ans[ans_size-1][1] >intervals[i][0]){
                ans[ans_size-1][1]=max(ans[ans_size-1][1],intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};