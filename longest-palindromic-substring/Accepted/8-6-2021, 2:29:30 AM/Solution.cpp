// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "" ;
        int n = s.size();
        int dp[n+1][n+1];
        
        
        int diff = -1;
        string single ="";
        
        
    
        for(int i =0 ;i<n;i++){
            dp[i][i] = 1;
            diff = 1;
        }
        
        string doublestring ="";
        for(int i =0 ;i<n-1;i++){
            dp[i][i+1]= s[i] == s[i+1] ? 1:0;
            if(dp[i][i+1] ==1 && doublestring.size() ==0 ){
               diff = 2;
                doublestring += s[i];
                doublestring += s[i+1];

            }
        }
        int first =0 ;int last =0; 
        for(int len = 3;len <=n;len++){
            for(int i =0 ,j = i+ len-1;j<n;i++,j++){
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];

                if(dp[i][j] == 1 && (len>diff)){
                   first = i;
                    last =j;
                    diff = len;
                }
            }
        }
        
        
        if(diff >2){
            for(int i =first ;i<=last ;i++){
                ans +=s[i];
            }
            return ans ;
        }
        if(diff == 2) return  doublestring;
        single =s[0];
        return single ;
        
        
    }
};