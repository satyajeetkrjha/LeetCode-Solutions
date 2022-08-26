// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string


#include <iostream>
typedef long long int ll ;
class Solution {
public:
    int uniqueLetterString(string s) {
        const ll MOD = 1e9+7;
        int n = s.size();
        vector<ll> L(n ,-1);
        vector<ll> R(n ,-1);
    
        vector<ll> LastL(26,-1);
        vector<ll> LastR(26,n);
        
        for(int i =0 ;i<n;i++){
            L[i] = i - LastL[s[i]-'A'];
            LastL[s[i]-'A'] =i;
        }
        
        for(int i = n-1;i>=0 ;i--){
            R[i] = LastR[s[i]-'A']-i;
            LastR[s[i]-'A'] =i;
        }
        
        for(int i=0 ;i<n;i++){
            cout <<L[i]<< " ";
        }
        cout << endl;
        
        for(int i =0 ;i<n;i++){
            cout <<R[i]<< " ";
        }
        cout << endl;
        
        int ans =0 ;
        for(int i =0 ;i<n;i++){
            ans= (ans+(L[i]*R[i])%MOD)%MOD;
        }
        return ans ;
        
        
        
        
    }
};