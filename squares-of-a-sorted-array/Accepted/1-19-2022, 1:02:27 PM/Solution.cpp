// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int n = nums.size();
        int left =0 ;
        int right = n-1 ;
        vector <int> res(n ,0);
        int candidate;
        for(int i = n-1;i>=0 ;i--){
            if(abs(nums[left]) < abs(nums[right])){
                candidate = nums[right];
                right --;
            }
            else{
                candidate = nums[left];
                left++;
            }
            res[i]= candidate*candidate;
        }
        return res ;
    }
};