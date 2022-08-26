// https://leetcode.com/problems/largest-number

class Solution {
public:
    
    
    static bool compare(int a ,int b){
        string s = to_string(a);
        string t = to_string(b);
        return s+t > t+s;
    }
    
    string largestNumber(vector<int>& nums) {
    
        sort(nums.begin(),nums.end(),compare);
        string ans ; 
        for(int i =0 ;i<nums.size();i++){
            ans += to_string(nums[i]);
        }
        return nums[0] == 0 ?"0":ans ;
        
    } 
};