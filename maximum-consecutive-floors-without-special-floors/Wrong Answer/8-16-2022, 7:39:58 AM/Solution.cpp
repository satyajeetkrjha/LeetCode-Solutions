// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        int n = special.size();
        sort(special.begin(),special.end());
        int maxval = INT_MIN;
        for(int i =0  ;i<n-1;i++){
            maxval = max(maxval ,max(special[i+1]-special[i]-1,0));
        }
        maxval = max((special[1]-bottom),(top-special[n-1]));
        return maxval-1;
        
        
    }
};