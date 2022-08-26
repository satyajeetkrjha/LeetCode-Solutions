// https://leetcode.com/problems/subarray-sum-equals-k

#include <algorithm>
#include <map>
class Solution {
public:
    map <int,int > mi={{0,1}};
   
    int sum =0;
    int count = 0;
    int subarraySum(vector<int>& nums, int target) {
        for(int i =0 ;i<nums.size();i++){
            sum += nums[i];
            if(mi.find(sum -target)!=mi.end()){
                count += mi[sum-target];
            }
            mi[sum]++;
        }
        return count ;
    }
};