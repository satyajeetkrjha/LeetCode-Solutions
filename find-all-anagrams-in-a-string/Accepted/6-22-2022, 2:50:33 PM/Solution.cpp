// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector <int> hash(26,0);
        vector <int> pre_hash(26,0);
        int len =p.size() ;// size of window
        for(int i=0;i<p.size();i++){
            pre_hash[p[i]-'a']++;
        }
        int left =0;
        int right =0;
        while(right <s.size() ){
            hash[s[right]-'a']++;
            if(hash == pre_hash){
                ans.push_back(left);
            }
            right++;
            if(right-left+1>p.size()){
              hash[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};