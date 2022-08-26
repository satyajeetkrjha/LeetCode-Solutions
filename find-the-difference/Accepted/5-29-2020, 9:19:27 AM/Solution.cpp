// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        map <char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        char ans;
        for(int i=0;i<t.length();i++){
            if(m[t[i]]==0){
                ans =t[i];
                break;
            }
            else{
                m[t[i]]--;
            }
        }
        return ans;
    }
};