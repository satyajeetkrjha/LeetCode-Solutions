// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    typedef long long int ll;
    int minMoves(vector<int>& nums) {
        int num =INT_MAX;
        ll n = nums.size();
        ll sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            num = min(num,nums[i]);
        }
       return sum-n*num;
    }
};