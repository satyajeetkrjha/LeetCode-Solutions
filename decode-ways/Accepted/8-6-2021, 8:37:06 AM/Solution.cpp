// https://leetcode.com/problems/decode-ways

class Solution {
public:
    map <int ,int> memo;
    int recursivememo(string s ,int index){
        if(memo.find(index)!=memo.end()){
            return memo[index];
        }
        if(s[index]=='0'){
          return 0;        
        }
       
        if(index == s.length() || index == s.length()-1) {
            return 1;
        }
        
        
        int ans = recursivememo(s,index+1);
        if(stoi(s.substr(index,2)) <=26){
            ans+=recursivememo(s,index+2);
        }
        memo[index] =ans;
        return ans ;
    
    }
    int numDecodings(string s) {
        int ans = recursivememo(s,0);
        return ans ;
    }
};