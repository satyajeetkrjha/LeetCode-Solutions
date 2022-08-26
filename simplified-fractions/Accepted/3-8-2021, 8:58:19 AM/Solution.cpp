// https://leetcode.com/problems/simplified-fractions

#include <string>
#include <algorithm>

class Solution {
public:
    int gcd(int a, int b){
        if(a ==0){
            return b ;
        }
        return gcd(b%a,a);
    }
    vector<string> simplifiedFractions(int n) {
        vector <string > ans;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(gcd(i,j) ==1){
                    string s = to_string(j) +"/"+ to_string(i);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
    
   
  
    
};