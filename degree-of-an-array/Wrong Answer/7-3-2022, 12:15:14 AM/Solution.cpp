// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
           map <int,int> count ,first ;
        int degree = 0 ;
        int res =0;
        for(int i =0 ;i< nums.size();i++){
             if(first.count(nums[i]) == 0){
                 first[nums[i]] = i;
             }
            else if(++count[nums[i]]> degree){
                degree = count[nums[i]];
                res = i - first[nums[i]]+1 ;
            }
            else if(count[nums[i]] == degree){
                res  = min(res , i-first[nums[i]]+1);
            }
        }
        return res ;
    }
};