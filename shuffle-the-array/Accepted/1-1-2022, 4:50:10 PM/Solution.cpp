// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> res(2*n ,0);
        int index =0;
        for(int i =0 ,j=n;index<2*n;i++,j++){
            res[index++]  = nums[i];
            res[index++] = nums[j];
        }
        return res ;
    }
};