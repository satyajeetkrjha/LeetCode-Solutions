// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestprev  = values[0] +0;
        int res = bestprev + values[1] + (0-1);
        for(int j = 1;j<values.size();j++){
            res = max(res, bestprev + values[j]-j);
            bestprev = max(bestprev, values[j]+j);
        }
        return  res ;
    }
};