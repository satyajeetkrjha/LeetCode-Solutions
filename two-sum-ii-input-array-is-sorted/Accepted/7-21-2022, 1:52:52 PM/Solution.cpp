// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res ;
        int start =0 ;
        int end = numbers.size() -1 ;
        while(start <end){
            int sum = numbers[start]+numbers[end];
            if(target == sum){
                res.push_back(start+1);
                res.push_back(end+1);
                return res ;
            }
            if(sum <target)
                start ++;
            else if(sum >target)
                end --;
        }
        return res ;
    }
};