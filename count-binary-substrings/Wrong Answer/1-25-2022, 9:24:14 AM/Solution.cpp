// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector <int> groups(s.size());
        int idx =0 ;
        groups[idx]=1 ;
        for(int i =1 ;i<s.size();i++){
            if(s[i]!=s[i-1]){
                idx++;
                groups[idx]++;
            }
            else{
                groups[idx]++;
            }
        }
        int ans =0 ;
        for(int i =1 ;i<= idx;i++){
            ans += min(groups[idx-1],groups[idx]);
        }
        return ans ;
    }
};