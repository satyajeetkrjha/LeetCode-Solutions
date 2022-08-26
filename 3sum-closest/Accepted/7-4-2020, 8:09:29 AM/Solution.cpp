// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int low ,high;
        int diff =INT_MAX;
        sort( nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            low =i+1;
            high =nums.size()-1;
            while(low <high){
                int sum = nums[i]+nums[low]+nums[high];
                if(abs(target-sum)<abs(diff)){
                    diff =target-sum;
                }
                if(target>sum){
                    low++;
                }
                else{
                    high--;
                }
            }    
        }
        return target-diff;
    }
  
};