// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    set <int> s;
    int longestConsecutive(vector<int>& nums) {
        for(auto &it:nums){
            s.insert(it);
        }
        if(nums.size() ==0) return 0;
        int longest = 1;
        int currentstreak ;
        for(auto &it:nums){
            int num = it;
            currentstreak =1 ;
            if(s.find(num-1) == s.end()){
                while(s.find(num+1)!=s.end()){
                    currentstreak++;
                    longest = max(longest ,currentstreak);
                    num++;
                }
            }
        }
        return longest ;
        
    }
};