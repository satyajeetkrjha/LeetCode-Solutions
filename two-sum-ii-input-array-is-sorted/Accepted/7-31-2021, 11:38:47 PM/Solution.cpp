// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0 ;
        vector <int> ans;
        int right = numbers.size()-1;
        while(left <right){
            int sum = numbers[left]+numbers[right];
            if(sum == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            else if(sum <target){
                left++;
            }
            else {
                right--;
            }
        }
        return ans ;
    }
};