// https://leetcode.com/problems/minimum-health-to-beat-game

typedef long long ll ;
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        ll sum = 0 ;
        ll maxNum = -1;
        for(auto it:damage){
            maxNum = max(maxNum,it);
            sum += it;
        }
        
        return sum - min(maxNum,armor)+1;
    }
};