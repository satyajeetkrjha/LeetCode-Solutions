// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n = nums.size();
     map <int ,int > m;
     int count=0;
     for(int i=0;i<n;i++){
         int complement = k-nums[i];
         if(m.find(complement)!=m.end()){
             count++;
         }
         else{
             m[complement]++;
         }
         
     }
        return count;
    }
    
};