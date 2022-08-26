// https://leetcode.com/problems/maximum-split-of-positive-even-integers

typedef long long ll ;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector <ll> res ;
        if(finalSum %2 == 1){
            return res ;
        }
        int x = 2;
        int cur = 0 ;
        while(cur+x <= finalSum){
            res.push_back(x);
            cur = cur+x;
            x = x+2 ;
        }
        int sz = res.size();
        res[sz-1]+= cur-finalSum ;
        return res ;
        
    }
};