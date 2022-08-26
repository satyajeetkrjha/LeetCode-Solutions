// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

typedef long long ll;;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       
        int low = 0 ;
        int high = 1e5+1;
        int ans ;
        while(low <high){
            int mid =  low +(high-low)/2;
             ll sum =0 ;
            
            // sum part
            for(int i =0 ;i<nums.size();i++){
                if(nums[i]% mid == 0){
                    sum += nums[i]/mid;
                }
                else {
                    sum += (nums[i]/mid)+1 ;
                }
            }
            
            if(sum >threshold){
                low = mid+1;
            }
            else {
                ans =mid ;
                high = mid-1;
            }
        }
        return ans ;
    }
};