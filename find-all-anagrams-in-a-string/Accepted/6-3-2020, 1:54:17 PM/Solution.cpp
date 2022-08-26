// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector <int> hash(26,0);
        vector <int> pre_hash(26,0);// to calculate pre hash to do comparasion
        int len =p.size() ;// size of window
        for(int i=0;i<p.size();i++){
            pre_hash[p[i]-'a']++;
        }
        cout<<"prehash is"<<endl;
        // for(int i=0;i<s.size();i++){
        //     cout<<pre_hash[i]<<" ";
        // }
        cout<<endl;
        int left =0;
        int right =0;
        while(right <s.size() ){
            hash[s[right]-'a']++;
            // cout<<"hash is "<<endl;
            // for(int i=0;i<26;i++){
            //     cout<<hash[i]<<" ";
            // }
            cout<<endl;
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