// https://leetcode.com/problems/custom-sort-string


    string st ;
    bool customSort( char c,char t){
        return (st.find(c)<st.find(t));
    }
class Solution {
public:
    string customSortString(string S, string T) {
        st =S;
        sort(T.begin(),T.end(),customSort);
        return T;
        
    }
};
