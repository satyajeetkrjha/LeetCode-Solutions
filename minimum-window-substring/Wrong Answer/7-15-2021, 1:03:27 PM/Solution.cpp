// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0|| s.length() < t.length()){
            return "";
        }
        unordered_map <char ,int> m ;
        for(int i =0;i<t.length();i++){
            m[t[i]]++;
        }
        
        int count =0;
        int minlength =INT_MAX ;
        int end =0;
        int start =0;
        int leftstart =0;
        
        while(end <s.length()){
            // the s[i] word exists in the map
            if(m.find(s[end]) != m.end()){
                // cout<<"end is "<<end <<endl;
                m[s[end]]--;
                if(m[s[end]] >=0){
                    count++;
                }
            }
            while( count == t.length()){
                // update the min length and the starting index 
                minlength= min(minlength,(end-start)+1);
                leftstart = start;
                 
                
                // exists
                if(m.find(s[start]) != m.end()){
                    m[s[start]]++;
                    if(m[s[start]] >0){
                        count --;
                    }
                }
                start++; 
            }
            
            end++;
        }
        if(minlength >s.length()){
            return "";
        }
        return s.substr(leftstart,leftstart+minlength);
        
        
    }
};