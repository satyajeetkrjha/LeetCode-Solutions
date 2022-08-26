// https://leetcode.com/problems/single-number-iii

typedef long long int ll ;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      ll xorval = 0 ;
       for(int i =0 ;i< nums.size();i++){
           xorval = xorval ^nums[i];
       } 
        
        ll diff = xorval&(~xorval+1);
        int single1=0;
        int single2 =0 ;
        for(int i =0 ;i< nums.size();i++){
            if(diff & nums[i]){
                single1 ^= nums[i];
            }
            else {
                single2^=nums[i];
            }
        }
        return {single1,single2};
    }
};