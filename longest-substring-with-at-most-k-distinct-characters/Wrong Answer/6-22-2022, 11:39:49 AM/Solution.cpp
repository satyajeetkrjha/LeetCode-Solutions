// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      
        int left =0 ;
        int right = 0;
        map <char ,int> m;
        int maxlen =1;
        while(right < s.size()){
            m[s[right]] = right ;
            right++;
            if(m.size() == k+1){
                int lowestindex =INT_MAX;
                for(auto [elem,index]:m){
                    lowestindex = min(lowestindex,index);
                }
                m.erase(s[lowestindex]);
                left = lowestindex +1;
            }
            maxlen = max(maxlen ,right-left);
            
          
        }
        return maxlen;
        
        
    }
};