// https://leetcode.com/problems/product-of-array-except-self

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz=nums.size();
        int left[sz];
        int right[sz];
        left[0]=1;
        right[sz-1]=1;
        for(int i=1;i<sz;i++){
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=sz-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        std::vector <int> v;
        for(int i=0;i<sz;i++){
            v.push_back(left[i]*right[i]);
        }
        return v;
    }
};