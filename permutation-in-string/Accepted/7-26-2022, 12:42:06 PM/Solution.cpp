// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    vector<int> freq;
     bool allzerocheck(vector<int> &temp){
            for(int i =0 ;i<26;i++){
                if(freq[i]!=0)
                    return false ;
            }
            return true ;
        }
    bool checkInclusion(string s1, string s2) {
        freq.resize(26,0);
        int windowlen = s1.size();
        if(windowlen > s2.size())
            return false ;
        for(int i =0 ;i<windowlen;i++){
            freq[s1[i]-'a']++;
        }
        
        for(int i  =0 ;i<26 ;i++){
            cout << freq[i]<< " ";
        }
        cout << endl;
        
        for(int i =0 ;i<s2.size();i++){
            // first decrease the frequecy
            freq[s2[i]-'a']--;
            // exceeding window size  so now increment the one you had markred -1
            if(i - windowlen >=0){
                freq[s2[i-windowlen]-'a']++;
            }
            
            if(allzerocheck(freq))
                return true;
        }
        return false ;
        
       
        
    }
};