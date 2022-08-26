// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int max_straight_sum =INT_MIN;
        int min_straight_sum =INT_MAX;
        int temp_max_sum =0;
        int temp_min_sum =0;
        int arr_sum =0;
        for(int i=0;i<A.size();i++){
            arr_sum+=A[i];
            temp_max_sum +=A[i];
            max_straight_sum =max(max_straight_sum,temp_max_sum);
            temp_max_sum =temp_max_sum <0 ?0:temp_max_sum;
            
            temp_min_sum+=A[i];
            min_straight_sum =min(min_straight_sum,temp_min_sum);
            temp_min_sum =temp_min_sum >0 ? 0:temp_min_sum;
            
            
        }
        if(arr_sum == temp_min_sum)
            return max_straight_sum;
        else
            return max(max_straight_sum,arr_sum-min_straight_sum);
    }
};