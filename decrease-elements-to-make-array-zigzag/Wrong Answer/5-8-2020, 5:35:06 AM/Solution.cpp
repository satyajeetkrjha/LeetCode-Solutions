// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag

#include <iostream>
#include <algorithm> 
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans=1000000;
        for(int i=1;i< nums.size();i++){
            int diff =abs(nums[i]-nums[i-1])+1;
            cout << "diff is" << diff <<endl;
            cout<<"ans befoe is "<<ans<<endl;
            ans =min(ans,diff);
            cout << "ans is " << ans <<endl;
        }
        return ans;
    }
};