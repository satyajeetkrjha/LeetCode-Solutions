// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left  =0 ;
        int right =0 ;
        int sz = s.size();
        map <char ,int> m ;
        int maxlen =0;
        if(sz<3) return sz;
        while(right < sz){
            m[s[right]]= right ;
            right++;
            if(m.size() == 3){
                int minimumindex =INT_MAX;
                for(auto[key,value]:m){
                    minimumindex = min(minimumindex,value) ;
                }
                m.erase(s[minimumindex]);
                left = minimumindex+1;
            }
            maxlen = max(maxlen ,right-left);
            
        }
        return maxlen ;
    }
};