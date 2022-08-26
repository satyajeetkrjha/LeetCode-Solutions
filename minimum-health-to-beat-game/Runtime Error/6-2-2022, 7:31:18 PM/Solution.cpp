// https://leetcode.com/problems/minimum-health-to-beat-game

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int sum = 0 ;
        int maxNum = -1;
        for(auto it:damage){
            maxNum = max(maxNum,it);
            sum += it;
        }
        
        return sum - min(maxNum,armor)+1;
    }
};