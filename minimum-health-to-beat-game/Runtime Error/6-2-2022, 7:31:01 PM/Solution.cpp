// https://leetcode.com/problems/minimum-health-to-beat-game

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int sum = 0 ;
        int maxNum =INT_MIN;
        for(auto it:damage){
            maxNum = max(maxNum,it);
            sum += it;
        }
        
        return sum - min(maxNum,armor)+1;
    }
};