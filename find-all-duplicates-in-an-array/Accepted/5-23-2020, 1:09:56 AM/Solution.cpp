// https://leetcode.com/problems/find-all-duplicates-in-an-array

#include <iostream>
#include <cmath>     
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int index=abs(nums[i])-1;
            if(nums[index] <0) 
                v.push_back(index+1);
            nums[index]=-nums[index];
            
        }
        return v;
    }
};