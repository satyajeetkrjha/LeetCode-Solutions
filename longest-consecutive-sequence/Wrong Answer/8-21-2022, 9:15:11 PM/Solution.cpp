// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s;
        for(auto &it:nums){
            s.insert(it);
        }
        // now ourt set contains all numbers in sorted number 
        int longeststreak =1 ;
        int currentstreak ;
        for(auto &it:nums){
            currentstreak =1 ;
            auto num = it ;
            if(s.find(num-1) == s.end()){
                while(s.find(num+1)!=s.end()){
                    currentstreak++;
                    longeststreak =max(longeststreak,currentstreak);
                    num++;
                }
            }
        }
        return longeststreak ;
    }
};