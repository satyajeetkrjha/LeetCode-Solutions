// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    map <pair <int ,int> ,int> m;
    string s ,t ;
    int len1 ,len2 ;
    int backtrack(int i ,int j){
        if( j == len2)
            return 1 ;
        else if ( i == len1)
            return 0 ;
        auto find = m.find({i,j});
        if(find!=m.end()){
            return m[{i,j}];
        }
        
        if(s[i] == t [j]){
            m[{i,j}] = backtrack(i+1,j+1) +backtrack(i+1,j);
        }
        else{
            m[{i,j}] = backtrack(i+1,j);
        }
        return m[{i,j}];
    }
    int numDistinct(string s1, string t1) {
        s = s1;
        t = t1 ;
        len1 = s.size();len2 = t.size();
        return backtrack(0,0);
    }
};