// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    string s,t;
    int m ,n;
    
    int backtrack(int i ,int j){
        if( j == m ) return 1 ; // you reached end of the second string 
        else if( i == n) return 0 ;// you reached end of the first string 
        if(s[i] == t[j])
            return backtrack(i+1,j+1) + backtrack(i+1,j);
        else
            return backtrack(i+1,j);
    }
    
    
    int numDistinct(string s1, string t1) {
        s= s1,t = t1 ;
         n = s.size();
         m = t.size();
        return backtrack(0,0);
    }
};