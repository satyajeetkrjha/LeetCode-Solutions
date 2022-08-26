// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        map <char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            m[t[i]]--;
        }
        int ans =0;
        for(auto i:m){
            if(i.second>0){
                ans+=i.second;
            }
        }
        return ans;
    }
};