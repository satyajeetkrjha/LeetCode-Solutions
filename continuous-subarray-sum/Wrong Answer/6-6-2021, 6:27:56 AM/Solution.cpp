// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map <int ,int > m; // sum and index
        m[0] = -1;
        int sum =0;
        for(int i =0;i< nums.size();i++){
            sum = sum +nums[i];
            if( k!= 0){
                sum = sum %k;
            }
            if(m[sum] >=0 && (i -m[sum]+1)>=2){
                return true;
            }
            m[sum] =i;
        }
        return false;
    }
};