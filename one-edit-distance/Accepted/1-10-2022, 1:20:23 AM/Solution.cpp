// https://leetcode.com/problems/one-edit-distance

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        cout <<s.substr(0)<< endl;
        cout <<t.substr(0)<< endl;
        for(int i =0 ;i<min(m,n);i++){
            if(s[i]!= t[i]){
                if(m == n){
                    return s.substr(i+1) == t.substr(i+1);
                }
                else if( n < m){
                    return s.substr(i)  == t.substr(i+1);
                }
                else {
                    return s.substr(i+1) == t.substr(i);
                }
            }
        }
        return abs(m-n) == 1;
        
    }
};