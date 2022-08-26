// https://leetcode.com/problems/replace-elements-in-an-array

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
      // our map will store the element and the index of that element in nums
        map <int ,int> m ;
        for(int i = 0 ;i<nums.size();i++){
            int elem = nums[i];
            m[elem] = i ;
        }
        
        for(int i =0 ;i<operations.size();i++){
            int x = operations[i][0];
            int y = operations[i][1];
            int temp = m[x] ; // store index 
            nums[m[x]] = y; // replace in array
            m[y]= temp;            // change the index
        }
        return nums ;
    }
};