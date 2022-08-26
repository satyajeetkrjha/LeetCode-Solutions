// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        for(int i = n-1;i>0 ;i--){
            string s1 = words[i] ; string s2 = words[i-1];
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1 == s2){
                words.erase(words.begin()+i);
            }
        }
        return words ;
    }
};