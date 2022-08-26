// https://leetcode.com/problems/jump-game

#include <iostream>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size()-1;
        if(n<=1)
            return true;
        int lastIndex =n-1;
        for(int i=n-1;i>=0;i--){
            if(lastIndex+nums[i]>=n-1){
                lastIndex=i;
            cout<<"lastindex is"<<lastIndex<<endl;
            cout <<"reachable is"<<lastIndex+nums[i]<<endl;    
            }
        }
        if(lastIndex ==0){
            return true;
        }
        return false;
    }
};