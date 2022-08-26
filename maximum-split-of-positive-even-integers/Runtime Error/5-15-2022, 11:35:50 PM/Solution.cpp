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
        cout <<"cur is "<< cur << endl;
        int sz = res.size();
        cout <<"res[sz-1] is "<< res[sz-1]<< endl;
        res[sz-1]+= abs(cur-finalSum) ;
        return res ;
        
    }
};