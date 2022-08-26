// https://leetcode.com/problems/missing-element-in-sorted-array

class Solution {
public:
    //this function tells us total missing elements till that index 
    int missing(int index,vector <int> &nums){
        return nums[index] -nums[0]-index;
    }
    int missingElement(vector<int>& nums, int k) {
        // we need to find that index such that missings[idx-1]<k <= missings[idx+1]
        int idx =0;
        while (missing(idx,nums)<k){
            idx++;
        }
        cout <<"idx is "<<idx<<endl;
        return nums[idx-1]+(k -missing(idx-1,nums));
        
    }
};