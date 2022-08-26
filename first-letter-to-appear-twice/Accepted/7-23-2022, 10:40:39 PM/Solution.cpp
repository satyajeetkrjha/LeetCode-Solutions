// https://leetcode.com/problems/first-letter-to-appear-twice

class Solution {
public:
    char repeatedCharacter(string s) {
        map <char ,vector <int> > m;
        for(int i =0 ;i<s.size();i++){
            char ch = s[i];
            m[ch].push_back(i);
        }
        
        int minVal = INT_MAX;
        char ans ;
        for(char a='a';a<='z';a++){
            vector <int> vec = m[a];
            if(vec.size() >=2 && minVal >vec[1]){
                minVal = vec[1];
                ans= a;
            }
        }
        return ans ;
        
    }
};