// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
   
    
    vector<int> findAnagrams(string s, string p) {
        
         vector <int> hash(26,0);
        vector <int> prehash(26,0);// to calculate pre hash to do comparasion
        for(int i =0 ;i<26;i++){
            hash[i] = prehash[i]= 0;
        }
         
        for(int i =0 ;i<p.size();i++){
            prehash[p[i]-'a']++;
        }
        for(int i =0 ;i<26;i++){
            cout << prehash[i]<< " ";
        }
        cout << endl;
        
        int left =0 ;
        int right = 0 ;
        vector <int> res ;
        while(right <s.size()){
            hash[s[right]-'a']++;
            
            
            if(hash == prehash){
                res.push_back(left);
            }
            
            right ++;
            if((right- left+1) > p.size()){
               hash[s[left]-'a']--;
                left++;
            }
        }
        return res ;
    }
};
