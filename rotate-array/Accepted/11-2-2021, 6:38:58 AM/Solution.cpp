// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k % n ;
        // first revesre the entire arary
        reversevector(nums,0 ,n-1);
        // revesre the first k part of array
        reversevector(nums,0,k-1);
        // revesre the k to last index of array
        reversevector(nums,k,n-1);
    }
    void reversevector(vector <int> &nums,int start ,int end){
        while(start < end){
            swap(nums[start],nums[end]);
            end--;
            start++;
        }
    }
};